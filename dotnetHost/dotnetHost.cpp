#include "dotnetHost.h"

//Iolite api
const struct io_api_manager_i* io_api_manager = 0;

// Declare the io_logging interface
static const io_logging_i* io_logging = nullptr;

// Interfaces
static io_user_task_i io_user_task = {};

IO_API_EXPORT io_uint32_t IO_API_CALL get_api_version()
{
    // Inform IOLITE which version of the API you are using
    return IO_API_VERSION;
}


#define MAX_PATH 260

using string_t = std::basic_string<char_t>;

// Function pointer types for hostfxr functions
hostfxr_initialize_for_runtime_config_fn init_fptr = nullptr;
hostfxr_get_runtime_delegate_fn get_delegate_fptr = nullptr;
hostfxr_close_fn close_fptr = nullptr;

//// Define the function pointer type for the managed method (ComponentEntryPoint)
//using component_entry_point_fn = int (*)();  // Matches the signature of 'Run'

// Function to load the library and resolve exported function addresses
void* load_library(const char_t* library_path) {
#ifdef _WIN32
    return LoadLibraryW(library_path); // Windows-specific load
#else
    return dlopen(library_path, RTLD_LAZY | RTLD_LOCAL);  // Linux-specific load
#endif
}

void* get_export(void* lib, const char* export_name) {
#ifdef _WIN32
    return (void*)GetProcAddress((HMODULE)lib, export_name);
#else
    return dlsym(lib, export_name);
#endif
}

// Function to load hostfxr and get required functions
bool load_hostfxr() {
    // Pre-allocate a large buffer for the path to hostfxr
    char_t buffer[MAX_PATH];
    size_t buffer_size = sizeof(buffer) / sizeof(char_t);

    // Load nethost and get hostfxr path
    int rc = get_hostfxr_path(buffer, &buffer_size, nullptr);
    if (rc != 0) {
        io_logging->log_error("Failed to locate hostfxr");
        return false;
    }

    // Load hostfxr and get desired exports
    void* lib = load_library(buffer); // Implement load_library to load the shared library
    init_fptr = (hostfxr_initialize_for_runtime_config_fn)get_export(lib, "hostfxr_initialize_for_runtime_config");
    get_delegate_fptr = (hostfxr_get_runtime_delegate_fn)get_export(lib, "hostfxr_get_runtime_delegate");
    close_fptr = (hostfxr_close_fn)get_export(lib, "hostfxr_close");

    return (init_fptr && get_delegate_fptr && close_fptr);
}

// Function to load and initialize the .NET runtime and get the function pointer to load assemblies
load_assembly_and_get_function_pointer_fn get_dotnet_load_assembly(const char_t* config_path) {
    void* load_assembly_and_get_function_pointer = nullptr;
    hostfxr_handle cxt = nullptr;
    int rc = init_fptr(config_path, nullptr, &cxt);
    if (rc != 0 || cxt == nullptr) {
        io_logging->log_error("Initialization failed");
        close_fptr(cxt);
        return nullptr;
    }

    // Get the load assembly function pointer
    rc = get_delegate_fptr(cxt, hdt_load_assembly_and_get_function_pointer, &load_assembly_and_get_function_pointer);
    if (rc != 0 || load_assembly_and_get_function_pointer == nullptr) {
        io_logging->log_error("Failed to get delegate");
    }

    close_fptr(cxt);
    return reinterpret_cast<load_assembly_and_get_function_pointer_fn>(load_assembly_and_get_function_pointer);
}

typedef void (CORECLR_DELEGATE_CALLTYPE* custom_entry_point_fn)(float delta_t);
// Function pointer to managed delegate
custom_entry_point_fn on_tick_entry_point = nullptr;

void init() {
    // Load hostfxr and get the required functions
    if (!load_hostfxr()) {
        io_logging->log_error("Failed to load hostfxr");
    }

    // Define the path to the configuration file
    const char_t* runtime_config_path = STR("IOLITE_Library.runtimeconfig.json");  // Ensure the correct path

    // Get function pointer for loading the assembly
    load_assembly_and_get_function_pointer_fn load_fn = get_dotnet_load_assembly(runtime_config_path);
    if (!load_fn) {
        io_logging->log_error("Failed to get load assembly function pointer");
    }

    const string_t dotnetlib_path = STR("IOLITE_Library.dll");
    const char_t* dotnet_type = STR("IOLITE_Library.Class1, IOLITE_Library");
    const char_t* dotnet_type_method = STR("Run");

    // Function pointer to managed delegate
    component_entry_point_fn hello = nullptr;
    int rc = load_fn(
        dotnetlib_path.c_str(),
        dotnet_type,
        dotnet_type_method,
        nullptr /*delegate_type_name*/,
        nullptr,
        (void**)&hello);

    assert(rc == 0 && hello != nullptr && "Failure: load_assembly_and_get_function_pointer()");

    struct lib_args
    {
        const char_t* message;
        int number;
    };
    for (int i = 0; i < 3; ++i)
    {

        lib_args args
        {
            STR("from host!"),
            i
        };

        hello(&args, sizeof(args));

    }

    
    int on_tick_rc = load_fn(
        dotnetlib_path.c_str(),
        dotnet_type,
        STR("On_Tick"),
        STR("IOLITE_Library.Class1+On_Tick_Delegate, IOLITE_Library"),
        nullptr,
        (void**)&on_tick_entry_point);

    assert(rc == 0 && on_tick_entry_point != nullptr && "Failure: load_assembly_and_get_function_pointer()");

    

    // Close the runtime handle
    close_fptr(nullptr);
}


//On tick
void on_tick(io_float32_t delta_t)
{

    on_tick_entry_point(delta_t);
}



IO_API_EXPORT io_int32_t IO_API_CALL load_plugin(void* api_manager)
{
    // Ensure we can keep accessing the API manager after loading the plugin
    io_api_manager = (const struct io_api_manager_i*)api_manager;

    io_user_task = {};
    io_user_task.on_tick = on_tick;
    io_api_manager->register_api(IO_USER_TASK_API_NAME, &io_user_task);

    // Do something with the API manager, set up your plugin, etc.
    io_logging = (const io_logging_i*)io_api_manager->find_first(IO_LOGGING_API_NAME);
    init();
    io_logging->log_warning("Initilized DotnetHost");

    return 0; // Return a value < 0 to indicate that the loading of your plugin
    // has failed (depedency not available, etc.)
}



IO_API_EXPORT void IO_API_CALL unload_plugin()
{
    // Clean up here
}

void restart_plugin()
{
	unload_plugin();
	load_plugin((void*)io_api_manager);
}
﻿#include "dotnetHost.h"

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
        std::cerr << "Failed to locate hostfxr" << std::endl;
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
        std::cerr << "Initialization failed: " << std::hex << rc << std::endl;
        close_fptr(cxt);
        return nullptr;
    }

    // Get the load assembly function pointer
    rc = get_delegate_fptr(cxt, hdt_load_assembly_and_get_function_pointer, &load_assembly_and_get_function_pointer);
    if (rc != 0 || load_assembly_and_get_function_pointer == nullptr) {
        std::cerr << "Failed to get delegate" << std::endl;
    }

    close_fptr(cxt);
    return reinterpret_cast<load_assembly_and_get_function_pointer_fn>(load_assembly_and_get_function_pointer);
}



int main() {
    // Load hostfxr and get the required functions
    if (!load_hostfxr()) {
        std::cerr << "Failed to load hostfxr" << std::endl;
        return EXIT_FAILURE;
    }

    // Define the path to the configuration file
    const char_t* runtime_config_path = L"IOLITE_Library.runtimeconfig.json";  // Ensure the correct path

    // Get function pointer for loading the assembly
    load_assembly_and_get_function_pointer_fn load_fn = get_dotnet_load_assembly(runtime_config_path);
    if (!load_fn) {
        std::cerr << "Failed to get load assembly function pointer" << std::endl;
        return EXIT_FAILURE;
    }

    const string_t dotnetlib_path = STR("IOLITE_Library.dll");
    const char_t* dotnet_type = STR("IOLITE_Library.Class1, IOLITE_Library");
    const char_t* dotnet_type_method = STR("Run");
    // <SnippetLoadAndGet>
    // Function pointer to managed delegate
    component_entry_point_fn hello = nullptr;
    int rc = load_fn(
        dotnetlib_path.c_str(),
        dotnet_type,
        dotnet_type_method,
        nullptr /*delegate_type_name*/,
        nullptr,
        (void**)&hello);
    // </SnippetLoadAndGet>
    assert(rc == 0 && hello != nullptr && "Failure: load_assembly_and_get_function_pointer()");

    //
    // STEP 4: Run managed code
    //
    struct lib_args
    {
        const char_t* message;
        int number;
    };
    for (int i = 0; i < 3; ++i)
    {
        // <SnippetCallManaged>
        lib_args args
        {
            STR("from host!"),
            i
        };

        hello(&args, sizeof(args));
        // </SnippetCallManaged>
    }


    // Close the runtime handle
    close_fptr(nullptr);

    return EXIT_SUCCESS;
}
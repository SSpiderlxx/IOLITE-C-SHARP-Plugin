#include "dotnetHost.h"

#define HOSTFXR_PATH_SIZE 256

// Function pointers for hostfxr functions
hostfxr_initialize_for_runtime_config_fn init_fn = nullptr;
hostfxr_get_runtime_delegate_fn get_delegate_fn = nullptr;
hostfxr_close_fn close_fn = nullptr;

// Load the nethost library and resolve get_hostfxr_path
int load_nethost_and_get_hostfxr_path(char_t* hostfxrPath, size_t size) {
#ifdef _WIN32
    // Load nethost.dll
    HMODULE nethost_lib = LoadLibraryA("nethost.dll");
    if (!nethost_lib) {
        std::cerr << "Failed to load nethost.dll" << std::endl;
        return -1;
    }

    // Resolve get_hostfxr_path
    auto get_hostfxr_path_fn = (decltype(&get_hostfxr_path))GetProcAddress(nethost_lib, "get_hostfxr_path");
    if (!get_hostfxr_path_fn) {
        std::cerr << "Failed to resolve get_hostfxr_path in nethost.dll" << std::endl;
        return -1;
    }

    // Call get_hostfxr_path
    return get_hostfxr_path_fn(hostfxrPath, &size, nullptr);

#else
    // Load libnethost.so
    void* nethost_lib = dlopen("libnethost.so", RTLD_LAZY | RTLD_LOCAL);
    if (!nethost_lib) {
        std::cerr << "Failed to load libnethost.so" << std::endl;
        return -1;
    }

    // Resolve get_hostfxr_path
    auto get_hostfxr_path_fn = (decltype(&get_hostfxr_path))dlsym(nethost_lib, "get_hostfxr_path");
    if (!get_hostfxr_path_fn) {
        std::cerr << "Failed to resolve get_hostfxr_path in libnethost.so" << std::endl;
        return -1;
    }

    // Call get_hostfxr_path
    return get_hostfxr_path_fn(hostfxrPath, &size, nullptr);
#endif
}

// Helper function to load hostfxr
void* load_hostfxr() {
    char_t hostfxrPath[HOSTFXR_PATH_SIZE];
    size_t size = HOSTFXR_PATH_SIZE;

    // Locate the hostfxr library path
    int rc = load_nethost_and_get_hostfxr_path(hostfxrPath, size);
    if (rc != 0) {
        std::cerr << "Failed to locate hostfxr" << std::endl;
        return nullptr;
    }

#ifdef _WIN32
    HMODULE lib = LoadLibraryW(hostfxrPath);  // Use LoadLibraryW for wide-character strings
    if (!lib) {
        std::cerr << "Failed to load hostfxr.dll" << std::endl;
        return nullptr;
    }
#else
    void* lib = dlopen(hostfxrPath, RTLD_LAZY | RTLD_LOCAL);
    if (!lib) {
        std::cerr << "Failed to load libhostfxr.so" << std::endl;
        return nullptr;
    }
#endif

    return lib;
}

int main() {
    // Load hostfxr library
    void* hostfxr = load_hostfxr();
    if (!hostfxr) {
        std::cerr << "Hostfxr loading failed" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Hostfxr loaded successfully" << std::endl;
    return EXIT_SUCCESS;
}

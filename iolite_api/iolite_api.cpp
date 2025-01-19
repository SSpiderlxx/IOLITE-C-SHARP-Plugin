#include "inc/iolite_api.h"


//Iolite api
const struct io_api_manager_i* io_api_manager = 0;

// Declare the io_logging interface
static const io_logging_i* io_logging = nullptr;

IO_API_EXPORT io_uint32_t IO_API_CALL get_api_version()
{
    // Inform IOLITE which version of the API you are using
    return IO_API_VERSION;
}

// Plugin load function to set up the logging interface
IO_API_EXPORT io_int32_t IO_API_CALL load_plugin(const void* api_manager)
{
    io_api_manager = (const io_api_manager_i*)api_manager;

    // Retrieve the logging interface
    io_logging = (const io_logging_i*)io_api_manager->find_first(IO_LOGGING_API_NAME);

    return 0;
}

IO_API_EXPORT void IO_API_CALL unload_plugin()
{
    // Clean up here
}

extern "C" __declspec(dllexport) void log_warning(const char* msg)
{
    // Ensure io_logging interface is available
    if (io_logging != nullptr)
    {
        io_logging->log_warning(msg);
    }
}
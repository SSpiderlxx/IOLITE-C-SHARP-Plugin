#include "inc/iolite_api.h"


//Iolite api
const struct io_api_manager_i* io_api_manager = 0;

// Declare the io_logging interface
static const io_logging_i* io_logging = nullptr;
// Delcate io_editor interface
static const io_editor_i* io_editor = nullptr;
// Delcate io_world interface
static const io_world_i* io_world = nullptr;

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
    // Retrieve the editor interface
    io_editor = (const io_editor_i*)io_api_manager->find_first(IO_EDITOR_API_NAME);
    // Retrieve the world interface
    io_world = (const io_world_i*)io_api_manager->find_first(IO_WORLD_API_NAME);

    return 0;
}

IO_API_EXPORT void IO_API_CALL unload_plugin()
{
    // Clean up here
}

// Provides access to the logging subsystem
IO_API_EXPORT void log_warning(const char* msg)
{
    // Ensure io_logging interface is available
    if (io_logging != nullptr)
    {
        io_logging->log_warning(msg);
    }
}

IO_API_EXPORT void log_info(const char* msg) {
    if (io_logging != nullptr) {
        io_logging->log_info(msg);
    }
}

IO_API_EXPORT void log_error(const char* msg) {
    if (io_logging != nullptr) {
        io_logging->log_error(msg);
    }
}

// Provides access to the editor
IO_API_EXPORT void select_node(io_ref_t node) {
    if (io_editor != nullptr) {
        io_editor->select_node(node);
    }
}

IO_API_EXPORT io_ref_t get_first_selected_node() {
    return io_editor->get_first_selected_node();
}

IO_API_EXPORT io_ref_t get_first_selected_entity() {
    return io_editor->get_first_selected_entity();
}

// Provides access to the world subsystem
IO_API_EXPORT io_ref_t get_root_node() {
    return io_world->get_root_node();
}

IO_API_EXPORT void load_world(const char* name) {
    io_world->load_world(name);
}

IO_API_EXPORT void save_world(const char* name) {
    io_world->save_world(name);
}

IO_API_EXPORT io_ref_t spawn_prefab(const char* name) {
    return io_world->spawn_prefab(name);
}

IO_API_EXPORT io_ref_t get_active_camera() {
    return io_world->get_active_camera();
}

IO_API_CALL io_float32_t get_current_time_factor() {
    return io_world->get_current_time_factor();
}



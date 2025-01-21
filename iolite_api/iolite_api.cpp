#include "inc/iolite_api.h"
#include "vector"

using namespace std;


//Iolite api
const struct io_api_manager_i* io_api_manager = 0;

// Declare the io_logging interface
static const io_logging_i* io_logging = nullptr;
// Delcate io_editor interface
static const io_editor_i* io_editor = nullptr;
// Delcate io_world interface
static const io_world_i* io_world = nullptr;
// Delcate io_component_node interface
static const io_component_node_i* io_component_node = nullptr;

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
    // Retrieve the component_node interface
    io_component_node = (const io_component_node_i*)io_api_manager->find_first(IO_COMPONENT_NODE_API_NAME);

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

IO_API_EXPORT io_float32_t get_current_time_factor() {
    return io_world->get_current_time_factor();
}

// Provides access to node components
IO_API_EXPORT io_ref_t create_node(const char* name) {
    return io_component_node->create(name);
}

IO_API_EXPORT io_ref_t create_node_with_parent(const char* name, io_ref_t parent, io_bool_t ignore_parent) {
    return io_component_node->create_with_parent(name, parent, ignore_parent);
}

IO_API_EXPORT void attach_node(io_ref_t parent, io_ref_t child, io_bool_t ignore_parent) {
    io_component_node->attach(parent, child, ignore_parent);
}

IO_API_EXPORT io_int32_t get_node_depth(io_ref_t node) {
    return io_component_node->get_depth(node);
}

IO_API_EXPORT io_ref_t get_node_parent(io_ref_t node) {
    return io_component_node->get_parent(node);
}

IO_API_EXPORT io_ref_t get_node_first_child(io_ref_t node) {
    return io_component_node->get_first_child(node);
}

IO_API_EXPORT io_ref_t get_node_next_sibling(io_ref_t node) {
    return io_component_node->get_next_sibling(node);
}

IO_API_EXPORT io_ref_t get_node_prev_sibling(io_ref_t node) {
    return io_component_node->get_prev_sibling(node);
}

IO_API_EXPORT io_aabb_t get_node_local_bounds(io_ref_t node) {
    return io_component_node->get_local_bounds(node);
}

IO_API_EXPORT io_aabb_t get_node_world_bounds(io_ref_t node) {
    return io_component_node->get_world_bounds(node);
}

IO_API_EXPORT void set_hidden(io_ref_t node, io_bool_t hidden) {
    io_component_node->set_hidden(node, hidden);
}

IO_API_EXPORT io_bool_t is_hidden(io_ref_t node) {
    return io_component_node->is_hidden(node);
}

IO_API_EXPORT void set_node_world_position(io_ref_t node, io_vec3_t pos) {
    io_component_node->set_world_position(node, pos);
}

IO_API_EXPORT io_vec3_t get_node_world_position(io_ref_t node) {
    return io_component_node->get_world_position(node);
}

IO_API_EXPORT void set_node_size(io_ref_t node, io_vec3_t size) {
    io_component_node->set_size(node, size);
}

IO_API_EXPORT io_vec3_t get_node_size(io_ref_t node) {
    return io_component_node->get_size(node);
}

IO_API_EXPORT void set_node_world_size(io_ref_t node, io_vec3_t size) {
    io_component_node->set_world_size(node, size);
}

IO_API_EXPORT io_vec3_t get_node_world_size(io_ref_t node) {
    return io_component_node->get_world_size(node);
}

IO_API_EXPORT void set_node_orientation(io_ref_t node, io_quat_t orient) {
    io_component_node->set_orientation(node, orient);
}

IO_API_EXPORT io_quat_t get_node_orientation(io_ref_t node) {
    return io_component_node->get_orientation(node);
}

IO_API_EXPORT void set_node_world_orientation(io_ref_t node, io_quat_t orient) {
    io_component_node->set_world_orientation(node, orient);
}

IO_API_EXPORT io_quat_t get_node_world_orientation(io_ref_t node) {
    return io_component_node->get_world_orientation(node);
}

IO_API_EXPORT io_vec3_t to_local_space(io_ref_t node, io_vec3_t pos) {
    return io_component_node->to_local_space(node, pos);
}

IO_API_EXPORT io_vec3_t to_local_space_direction(io_ref_t node, io_vec3_t dir) {
    return io_component_node->to_local_space_direction(node, dir);
}

IO_API_EXPORT io_vec3_t to_world_space(io_ref_t node, io_vec3_t pos) {
    return io_component_node->to_world_space(node, pos);
}

IO_API_EXPORT io_vec3_t to_world_space_direction(io_ref_t node, io_vec3_t dir) {
    return io_component_node->to_world_space_direction(node, dir);
}

IO_API_EXPORT void update_transforms(io_ref_t node) {
    io_component_node->update_transforms(node);
}

IO_API_EXPORT void update_transforms_jobified(const std::vector<io_ref_t>& nodes) {
    if (nodes.empty()) {
        io_logging->log_error("The nodes vector must not be empty.");
    }

    const io_ref_t* nodes_ptr = nodes.data();
    io_size_t nodes_length = static_cast<io_size_t>(nodes.size());
    io_component_node->update_transforms_jobified(nodes_ptr, nodes_length);
}

IO_API_EXPORT void intersect_point(io_vec3_t point,
    const std::vector<io_ref_t>& nodes,
    std::vector<io_ref_t>& intersecting_nodes,
    io_bool_t use_global_bounds) {
    // Check that the input vector `nodes` is not empty
    if (nodes.empty()) {
        io_logging->log_error("The nodes vector must not be empty.");
    }

    // Prepare the inputs
    const io_ref_t* nodes_ptr = nodes.data();
    io_size_t nodes_length = static_cast<io_size_t>(nodes.size());

    // Prepare the output for intersecting nodes
    io_size_t intersecting_nodes_length = 0; // This will be updated by the intersect_point function
    intersecting_nodes.clear(); // Ensure the output vector is empty

    // Reserve enough space in the output vector to accommodate the results
    intersecting_nodes.resize(nodes.size());

    // Call the intersect_point function
    io_component_node->intersect_point(point,
        nodes_ptr,
        nodes_length,
        intersecting_nodes.data(),
        &intersecting_nodes_length,
        use_global_bounds);

    // Resize the output vector to match the actual number of intersecting nodes
    intersecting_nodes.resize(intersecting_nodes_length);
}

IO_API_EXPORT void intersect_aabb(io_aabb_t aabb,
    const std::vector<io_ref_t>& nodes,
    std::vector<io_ref_t>& intersecting_nodes,
    io_bool_t use_global_bounds) {
    // Check that the input vector `nodes` is not empty
    if (nodes.empty()) {
        io_logging->log_error("The nodes vector must not be empty.");
        return;
    }

    // Prepare the inputs
    const io_ref_t* nodes_ptr = nodes.data();
    io_size_t nodes_length = static_cast<io_size_t>(nodes.size());

    // Prepare the output for intersecting nodes
    io_size_t intersecting_nodes_length = 0; // This will be updated by the intersect_aabb function
    intersecting_nodes.clear();              // Ensure the output vector is empty

    // Reserve enough space in the output vector to accommodate the results
    intersecting_nodes.resize(nodes.size());

    // Call the intersect_aabb function
    io_component_node->intersect_aabb(aabb,
        nodes_ptr,
        nodes_length,
        intersecting_nodes.data(),
        &intersecting_nodes_length,
        use_global_bounds);

    // Resize the output vector to match the actual number of intersecting nodes
    intersecting_nodes.resize(intersecting_nodes_length);
}

IO_API_EXPORT void intersect_sphere(io_sphere_t sphere,
    const std::vector<io_ref_t>& nodes,
    std::vector<io_ref_t>& intersecting_nodes,
    io_bool_t use_global_bounds) {
    // Check that the input vector `nodes` is not empty
    if (nodes.empty()) {
        io_logging->log_error("The nodes vector must not be empty.");
        return;
    }

    // Prepare the inputs
    const io_ref_t* nodes_ptr = nodes.data();
    io_size_t nodes_length = static_cast<io_size_t>(nodes.size());

    // Prepare the output for intersecting nodes
    io_size_t intersecting_nodes_length = 0; // This will be updated by the intersect_sphere function
    intersecting_nodes.clear();              // Ensure the output vector is empty

    // Reserve enough space in the output vector to accommodate the results
    intersecting_nodes.resize(nodes.size());

    // Call the intersect_sphere function
    io_component_node->intersect_sphere(sphere,
        nodes_ptr,
        nodes_length,
        intersecting_nodes.data(),
        &intersecting_nodes_length,
        use_global_bounds);

    // Resize the output vector to match the actual number of intersecting nodes
    intersecting_nodes.resize(intersecting_nodes_length);
}

#include "inc/iolite_api.h"
#include "vector"
#include <string>
#include <cstring>

using namespace std;


//Iolite api
const struct io_api_manager_i* io_api_manager = 0;

// Declare the io_logging interface
static const io_logging_i* io_logging = nullptr;
// Declare io_editor interface
static const io_editor_i* io_editor = nullptr;
// Declare io_world interface
static const io_world_i* io_world = nullptr;
// Declare io_component_node interface
static const io_component_node_i* io_component_node = nullptr;
// Declare io_component_tag_api
static const io_component_tag_i* io_component_tag = nullptr;
// Declare io_entity interface
static const io_entity_i* io_entity = nullptr;
// Declare io_input interface
static const io_input_system_i* io_input_system = nullptr;
// Declare io_animation_system interface
static const io_animation_system_i* io_animation_system = nullptr;
// Declare io_physics interface
static const io_physics_i* io_physics = nullptr;
// Delcare io_ui interface
static const io_ui_i* io_ui = nullptr;
// Declare Filesystem interface
static const io_filesystem_i* io_filesystem = nullptr;
// Declare pathfinding interface
static const io_pathfinding_i* io_pathfinding = nullptr;
// Sound interface
static const io_sound_i* io_sound = nullptr;
// Declare custom data component interface
static const io_component_custom_data_i* io_component_custom_data = nullptr;
// Decalre character controller interface
static const io_component_character_controller_i* io_component_character_controller = nullptr;
// Delcare io_component_flipbook_animation interface
static const io_component_flipbook_animation_i* io_component_flipbook_animation = nullptr;
// Delcare io_component_camera_controller interface
static const io_component_camera_controller_i* io_component_camera_controller = nullptr;

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
    // Retrieve the componet tag interface
    io_component_tag = (const io_component_tag_i*)io_api_manager->find_first(IO_COMPONENT_TAG_API_NAME);
	// Retrieve the entity interface
	io_entity = (const io_entity_i*)io_api_manager->find_first(IO_ENTITY_API_NAME);
	// Retrieve the input system interface
	io_input_system = (const io_input_system_i*)io_api_manager->find_first(IO_INPUT_SYSTEM_API_NAME);
	// Retrieve the animation system interface
	io_animation_system = (const io_animation_system_i*)io_api_manager->find_first(IO_ANIMATION_SYSTEM_API_NAME);
	// Retrieve the physics interface
	io_physics = (const io_physics_i*)io_api_manager->find_first(IO_PHYSICS_API_NAME);
	// Retrieve the ui interface
	io_ui = (const io_ui_i*)io_api_manager->find_first(IO_UI_API_NAME);
	// Retrieve the filesystem interface
	io_filesystem = (const io_filesystem_i*)io_api_manager->find_first(IO_FILESYSTEM_API_NAME);
	// Retrieve the sound interface
	io_sound = (const io_sound_i*)io_api_manager->find_first(IO_SOUND_API_NAME);
	// Retrieve the pathfinding interface
	io_pathfinding = (const io_pathfinding_i*)io_api_manager->find_first(IO_PATHFINDING_API_NAME);
	// Retrieve the custom data component interface
	io_component_custom_data = (const io_component_custom_data_i*)io_api_manager->find_first(IO_COMPONENT_CUSTOM_DATA_API_NAME);
    // Retrieve the character controller interface
    io_component_character_controller = (const io_component_character_controller_i*)io_api_manager->find_first(IO_COMPONENT_CHARACTER_CONTROLLER_API_NAME);
	// Retrieve the flipbook animation interface
	io_component_flipbook_animation = (const io_component_flipbook_animation_i*)io_api_manager->find_first(IO_COMPONENT_FLIPBOOK_ANIMATION_API_NAME);
    // Retrieve the camera controller interface
    io_component_camera_controller = (const io_component_camera_controller_i*)io_api_manager->find_first(IO_COMPONENT_CAMERA_CONTROLLER_API_NAME);

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
IO_API_EXPORT io_ref_t get_node_for_entity(io_ref_t entity) {
    return io_component_node->base.get_component_for_entity(entity);
}

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

// Provides access to tag components
IO_API_EXPORT io_ref_t component_tag_for_entity(io_ref_t entity) {
	return io_component_tag->base.get_component_for_entity(entity);
}

IO_API_EXPORT void find_entities_with_tag(
    const char* tag,
    std::vector<io_ref_t>& entities
) {
    // Prepare the output for entities
    io_size_t entities_length = 0; // This will be updated by the find_entities_with_tag function
    entities.clear();              // Ensure the output vector is empty

    // Reserve enough space in the output vector for potential results
    entities.resize(1024); // Start with a reasonably large size

    // Call the find_entities_with_tag function
    io_component_tag->find_entities_with_tag(
        tag,
        entities.data(),
        &entities_length
    );

    // Resize the output vector to match the actual number of entities found
    entities.resize(entities_length);
}

IO_API_EXPORT void add_tag(io_ref_t tag, const char* tag_name) {
    io_component_tag->add(tag, tag_name);
}

IO_API_EXPORT void remove_tag(io_ref_t tag, const char* tag_name) {
    io_component_tag->remove(tag, tag_name);
}

IO_API_EXPORT void get_tags(
    io_ref_t tag,
    std::vector<io_name_t>& tags
) {

    // Prepare the output for tags
    io_size_t tags_length = 0;        // This will be updated by the get_tags function
    tags.clear();                     // Ensure the output vector is empty

    // Reserve enough space in the output vector to accommodate the results
    tags.resize(1024);  // Start with a reasonably large size for potential results

    // Call the get_tags function
    io_component_tag->get_tags(
        tag,
        tags.data(),
        &tags_length
    );

    // Resize the output vector to match the actual number of tags
    tags.resize(tags_length);
}

// Provides access to the entity subsystem
IO_API_EXPORT io_ref_type_id_t get_entity_type_id() {
	return io_entity->get_type_id();
}

IO_API_EXPORT io_bool_t is_alive(io_ref_t entity) {
	return io_entity->is_alive(entity);
}

IO_API_EXPORT const char* get_name(io_ref_t entity) {
	return io_entity->get_name(entity);
}

IO_API_EXPORT io_uuid_t get_uuid(io_ref_t entity) {
	return io_entity->get_uuid(entity);
}

IO_API_EXPORT io_ref_t find_first_entity_with_name(const char* name) {
	return io_entity->find_first_entity_with_name(name);
}

IO_API_EXPORT io_ref_t find_entity_with_uuid(io_uuid_t uuid) {
	return io_entity->find_entity_with_uuid(uuid);
}

IO_API_EXPORT void find_entities_with_name(
    const char* name,
    std::vector<io_ref_t>& entities
) {
    // Prepare outputs
    io_size_t entities_length = 0;   // This will be updated by the native function
    entities.clear();                // Ensure the output vector is empty

    // Reserve enough space in the output vector to accommodate the results
    entities.resize(1024); // Start with a reasonably large size

    // Call the native function
    io_entity->find_entities_with_name(
        name,
        entities.data(),
        &entities_length
    );

    // Resize the output vector to match the actual number of entities found
    entities.resize(entities_length);
}

IO_API_EXPORT void find_entities_with_component(
    const char* component_type_name,
    std::vector<io_ref_t>& entities
) {
    // Prepare outputs
    io_size_t entities_length = 0;   // This will be updated by the native function
    entities.clear();                // Ensure the output vector is empty

    // Reserve enough space in the output vector to accommodate the results
    entities.resize(1024); // Start with a reasonably large size

    // Call the native function
    io_entity->find_entities_with_component(
        component_type_name,
        entities.data(),
        &entities_length
    );

    // Resize the output vector to match the actual number of entities found
    entities.resize(entities_length);
}

// Provides access to the input system
IO_API_EXPORT io_input_key_state get_key_state(io_input_key key, io_int8_t player_id) {
	return io_input_system->get_key_state(key, player_id);
}

IO_API_EXPORT io_float32_t get_axis_state(io_input_axis axis, io_uint8_t player_id) {
	return io_input_system->get_axis_state(axis, player_id);
}

IO_API_EXPORT io_vec2_t get_mouse_pos() {
	return io_input_system->get_mouse_pos();
}

IO_API_EXPORT io_vec2_t get_mouse_pos_viewport() {
	return io_input_system->get_mouse_pos_viewport();
}

IO_API_EXPORT io_vec2_t get_mouse_pos_relative() {
	return io_input_system->get_mouse_pos_relative();
}

IO_API_EXPORT void request_mouse_cursor() {
	io_input_system->request_mouse_cursor();
}

// Provides access to the animation system
IO_API_EXPORT io_handle64_t play_animation(io_ref_t node, const io_animation_system_animation_desc_t* desc) {
	return io_animation_system->play_animation(node, desc);
}

IO_API_EXPORT void stop_animation(io_handle64_t instance) {
	io_animation_system->stop_animation(instance);
}

IO_API_EXPORT void stop_animations(io_ref_t node) {
	io_animation_system->stop_animations(node);
}

IO_API_EXPORT void stop_all_animations(io_ref_t node) {
	io_animation_system->stop_all_animations(node);
}

IO_API_EXPORT void pause_animation(io_handle64_t instance) {
	io_animation_system->pause_animation(instance);
}

IO_API_EXPORT void resume_animtion(io_handle64_t instance) {
	io_animation_system->resume_animation(instance);
}

IO_API_EXPORT io_bool_t is_finished(io_handle64_t instance) {
	return io_animation_system->is_finished(instance);
}

IO_API_EXPORT void blend_in_out(io_handle64_t instance, io_float32_t target_blend_weight, io_float32_t duration, io_float32_t delay, io_bool_t stop_animation) {
	io_animation_system->blend_in_out(instance, target_blend_weight, duration, delay, stop_animation);
}

IO_API_EXPORT io_float32_t get_blend_weight(io_handle64_t instance) {
	return io_animation_system->get_blend_weight(instance);
}

IO_API_EXPORT void set_blend_weight(io_handle64_t instance, io_float32_t weight) {
	io_animation_system->set_blend_weight(instance, weight);
}

IO_API_EXPORT io_float32_t get_play_speed(io_handle64_t instance) {
	return io_animation_system->get_play_speed(instance);
}

IO_API_EXPORT void set_play_speed(io_handle64_t instance, io_float32_t speed) {
	io_animation_system->set_play_speed(instance, speed);
}

IO_API_EXPORT io_float32_t get_timeline_position(io_handle64_t instance) {
	return io_animation_system->get_timeline_position(instance);
}

IO_API_EXPORT void set_timeline_position(io_handle64_t instance, io_float32_t position) {
	io_animation_system->set_timeline_position(instance, position);
}

// Provides access to the physics system
IO_API_EXPORT void set_gravity(io_vec3_t gravity) {
	io_physics->set_gravity(gravity);
}

IO_API_EXPORT io_vec3_t get_gravity() {
	return io_physics->get_gravity();
}

IO_API_EXPORT io_physics_overlap_result_t overlap_sphere(io_vec3_t position, io_float32_t radius, io_uint32_t group_mask) {
	return io_physics->overlap_sphere(position, radius, group_mask);
}

IO_API_EXPORT io_physics_raycast_result_t sweep_sphere(io_vec3_t position, io_float32_t radius, io_vec3_t direction, io_float32_t distance, io_uint32_t group_mask) {
	return io_physics->sweep_sphere(position, radius, direction, distance, group_mask);
}

IO_API_EXPORT io_physics_raycast_result_t raycast(io_vec3_t origin, io_vec3_t direction, io_float32_t distance, io_uint32_t group_mask) {
	return io_physics->raycast(origin, direction, distance, group_mask);
}

// Provides access to the ui system
IO_API_EXPORT void draw_rect(io_vec4_t color) {
    if (io_ui != nullptr) {
        io_ui->draw_rect(color);
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT void draw_circle(io_vec4_t color) {
    if (io_ui != nullptr) {
        io_ui->draw_circle(color);
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT void draw_ngon(io_vec4_t color, io_uint32_t sides) {
    if (io_ui != nullptr) {
        io_ui->draw_ngon(color, sides);
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT void draw_image(const char* name, io_vec4_t tint) {
    if (io_ui != nullptr) {
        io_ui->draw_image(name, tint);
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT void draw_text(const char* text, io_ui_text_align_horizontal align_horizontal, io_ui_text_align_vertical align_vertical, io_ui_text_flag flags) {
    if (io_ui != nullptr) {
        io_ui->draw_text(text, align_horizontal, align_vertical, flags);
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT io_ui_rect_t calc_text_bounds(const char* text, io_ui_text_align_horizontal align_horizontal, io_ui_text_align_vertical align_vertical, io_ui_text_flag flags) {
    if (io_ui != nullptr) {
        return io_ui->calc_text_bounds(text, align_horizontal, align_vertical, flags);
    }
    else {
        io_logging->log_error("UI interface is not available.");
        return io_ui_rect_t{}; // Return default-initialized rectangle
    }
}

IO_API_EXPORT io_ui_rect_t get_last_text_bounds() {
    if (io_ui != nullptr) {
        return io_ui->get_last_text_bounds();
    }
    else {
        io_logging->log_error("UI interface is not available.");
        return io_ui_rect_t{};
    }
}

IO_API_EXPORT void push_transform(io_ui_anchor_t left, io_ui_anchor_t right,
    io_ui_anchor_t top, io_ui_anchor_t bottom,
    io_float32_t rotation) {
    if (io_ui != nullptr) {
        io_ui->push_transform(left, right, top, bottom, rotation);
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT void push_transform_preset(io_ui_anchor_preset preset,
    io_ui_anchor_offsets_t offsets,
    io_float32_t rotation) {
    if (io_ui != nullptr) {
        io_ui->push_transform_preset(preset, offsets, rotation);
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT void pop_transform() {
    if (io_ui != nullptr) {
        io_ui->pop_transform();
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT void push_scale_offset_for_base_size(io_vec2_t base_size, io_ui_aspect_mode aspect_mode) {
    if (io_ui != nullptr) {
        io_ui->push_scale_offset_for_base_size(base_size, aspect_mode);
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT void push_scale_offset(io_float32_t scale, io_vec2_t offset) {
    if (io_ui != nullptr) {
        io_ui->push_scale_offset(scale, offset);
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT void pop_scale_offset() {
    if (io_ui != nullptr) {
        io_ui->pop_scale_offset();
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT void push_style_var_float(io_ui_style_var var, io_float32_t value) {
    if (io_ui != nullptr) {
        io_ui->push_style_var_float(var, value);
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT void push_style_var_vec4(io_ui_style_var var, io_vec4_t value) {
    if (io_ui != nullptr) {
        io_ui->push_style_var_vec4(var, value);
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT void pop_style_var() {
    if (io_ui != nullptr) {
        io_ui->pop_style_var();
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT void clip_children() {
    if (io_ui != nullptr) {
        io_ui->clip_children();
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT void push_font_size(io_float32_t size) {
    if (io_ui != nullptr) {
        io_ui->push_font_size(size);
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT void pop_font_size() {
    if (io_ui != nullptr) {
        io_ui->pop_font_size();
    }
    else {
        io_logging->log_error("UI interface is not available.");
    }
}

IO_API_EXPORT io_bool_t intersects(io_vec2_t position) {
    if (io_ui != nullptr) {
        return io_ui->intersects(position);
    }
    else {
        io_logging->log_error("UI interface is not available.");
        return IO_FALSE;
    }
}

// Provides access to the filesystem

IO_API_EXPORT io_bool_t load_file_from_data_source(const char* filepath, std::vector<io_uint8_t>& data) {
    if (io_filesystem != nullptr) {
        io_size_t buffer_length = 0u;
        // First call to get the required buffer size
        io_bool_t result = io_filesystem->load_file_from_data_source(filepath, nullptr, &buffer_length);
        if (result == IO_TRUE && buffer_length > 0u) {
            data.resize(buffer_length);
            result = io_filesystem->load_file_from_data_source(filepath, data.data(), &buffer_length);
            if (result == IO_FALSE) {
                io_logging->log_error("Failed to load file data.");
                data.clear();
            }
        }
        else {
            io_logging->log_error("Failed to load file from data source or file is empty.");
            data.clear();
            result = IO_FALSE;
        }
        return result;
    }
    else {
        io_logging->log_error("Filesystem interface is not available.");
        return IO_FALSE;
    }
}

IO_API_EXPORT io_bool_t create_or_retrieve_user_directory(const char* subdirectory, std::string& directory_path) {
    if (io_filesystem != nullptr) {
        io_size_t buffer_length = 0u;
        // First call to get the required buffer size
        io_filesystem->create_or_retrieve_user_directory(subdirectory, nullptr, &buffer_length);
        if (buffer_length > 0u) {
            directory_path.resize(buffer_length);
            io_filesystem->create_or_retrieve_user_directory(subdirectory, &directory_path[0], &buffer_length);
            // Trim any excess null characters
            directory_path.resize(strlen(directory_path.c_str()));
            return IO_TRUE;
        }
        else {
            io_logging->log_error("Failed to retrieve user directory.");
            directory_path.clear();
            return IO_FALSE;
        }
    }
    else {
        io_logging->log_error("Filesystem interface is not available.");
        directory_path.clear();
        return IO_FALSE;
    }
}

IO_API_EXPORT void watch_directory(const char* directory_path, io_filesystem_on_file_changed_function callback) {
    if (io_filesystem != nullptr) {
        io_filesystem->watch_directory(directory_path, callback);
    }
    else {
        io_logging->log_error("Filesystem interface is not available.");
    }
}

IO_API_EXPORT void watch_data_source_directory(const char* directory_path, io_filesystem_on_file_changed_function callback) {
    if (io_filesystem != nullptr) {
        io_filesystem->watch_data_source_directory(directory_path, callback);
    }
    else {
        io_logging->log_error("Filesystem interface is not available.");
    }
}

IO_API_EXPORT void remove_directory_watch(io_filesystem_on_file_changed_function callback) {
    if (io_filesystem != nullptr) {
        io_filesystem->remove_directory_watch(callback);
    }
    else {
        io_logging->log_error("Filesystem interface is not available.");
    }
}

// Provides access to the sound system

IO_API_EXPORT io_handle64_t play_sound_effect(const char* effect_name) {
    if (io_sound != nullptr) {
        return io_sound->play_sound_effect(effect_name);
    }
    else {
        io_logging->log_error("Sound interface is not available.");
        return { 0 };
    }
}

IO_API_EXPORT void stop_sound_effect(io_handle64_t effect_handle) {
    if (io_sound != nullptr) {
        io_sound->stop_sound_effect(effect_handle);
    }
    else {
        io_logging->log_error("Sound interface is not available.");
    }
}

IO_API_EXPORT void set_sound_position(io_handle64_t effect_handle, io_vec3_t position) {
    if (io_sound != nullptr) {
        io_sound->set_position(effect_handle, position);
    }
    else {
        io_logging->log_error("Sound interface is not available.");
    }
}

IO_API_EXPORT void get_audio_spectrum(std::vector<io_float32_t>& spectrum) {
    if (io_sound != nullptr) {
        const io_float32_t* spectrum_data = nullptr;
        io_size_t spectrum_length = 0;
        io_sound->get_spectrum(&spectrum_data, &spectrum_length);
        if (spectrum_length > 0 && spectrum_data != nullptr) {
            spectrum.assign(spectrum_data, spectrum_data + spectrum_length);
        }
        else {
            io_logging->log_error("Failed to retrieve audio spectrum.");
            spectrum.clear();
        }
    }
    else {
        io_logging->log_error("Sound interface is not available.");
        spectrum.clear();
    }
}

// Provides access to the pathfinding system

IO_API_EXPORT io_handle16_t find_path(io_vec3_t start, io_vec3_t end, const io_pathfinding_path_settings_t* settings) {
    if (io_pathfinding != nullptr) {
        return io_pathfinding->find_path(start, end, settings);
    }
    else {
        io_logging->log_error("Pathfinding interface is not available.");
        return io_handle16_t{ 0 };
    }
}

IO_API_EXPORT io_bool_t is_valid(io_handle16_t path_handle) {
    if (io_pathfinding != nullptr) {
        return io_pathfinding->is_valid(path_handle);
    }
    else {
        io_logging->log_error("Pathfinding interface is not available.");
        return IO_FALSE;
    }
}

IO_API_EXPORT void reset_path(io_handle16_t path_handle) {
    if (io_pathfinding != nullptr) {
        io_pathfinding->reset_path(path_handle);
    }
    else {
        io_logging->log_error("Pathfinding interface is not available.");
    }
}

IO_API_EXPORT void destroy_path(io_handle16_t path_handle) {
    if (io_pathfinding != nullptr) {
        io_pathfinding->destroy_path(path_handle);
    }
    else {
        io_logging->log_error("Pathfinding interface is not available.");
    }
}

IO_API_EXPORT io_bool_t is_path_found(io_handle16_t path_handle) {
    if (io_pathfinding != nullptr) {
        return io_pathfinding->is_path_found(path_handle);
    }
    else {
        io_logging->log_error("Pathfinding interface is not available.");
        return IO_FALSE;
    }
}

IO_API_EXPORT io_bool_t get_next_position_on_path(io_handle16_t path_handle, io_vec3_t* next_position) {
    if (io_pathfinding != nullptr) {
        return io_pathfinding->get_next_position_on_path(path_handle, next_position);
    }
    else {
        io_logging->log_error("Pathfinding interface is not available.");
        return IO_FALSE;
    }
}

IO_API_EXPORT void draw_path(io_handle16_t path_handle, io_vec4_t color, io_bool_t always_in_front) {
    if (io_pathfinding != nullptr) {
        io_pathfinding->draw_path(path_handle, color, always_in_front);
    }
    else {
        io_logging->log_error("Pathfinding interface is not available.");
    }
}

IO_API_EXPORT void draw_debug_geometry(io_handle16_t path_handle, io_bool_t always_in_front) {
    if (io_pathfinding != nullptr) {
        io_pathfinding->draw_debug_geometry(path_handle, always_in_front);
    }
    else {
        io_logging->log_error("Pathfinding interface is not available.");
    }
}
// Provides access to custom data components

IO_API_EXPORT io_ref_t get_custom_data_component_for_entity(io_ref_t entity) {
	if (io_component_custom_data != nullptr) {
		return io_component_custom_data->base.get_component_for_entity(entity);
	}
	else {
		io_logging->log_error("Custom data component interface is not available.");
		return { 0 };
	}
}

IO_API_EXPORT io_variant_t get_custom_data(io_ref_t custom_data, io_size_t index) {
    if (io_component_custom_data != nullptr) {
        return io_component_custom_data->get(custom_data, index);
    }
    else {
        io_logging->log_error("Custom data component interface is not available.");
        io_variant_t v;
        v.type.hash = 0;
        return v;
    }
}

IO_API_EXPORT void set_custom_data(io_ref_t custom_data, io_size_t index, io_variant_t value) {
    if (io_component_custom_data != nullptr) {
        io_component_custom_data->set(custom_data, index, value);
    }
    else {
        io_logging->log_error("Custom data component interface is not available.");
    }
}

IO_API_EXPORT void add_custom_data(io_ref_t custom_data, io_variant_t value) {
    if (io_component_custom_data != nullptr) {
        io_component_custom_data->add(custom_data, value);
    }
    else {
        io_logging->log_error("Custom data component interface is not available.");
    }
}

IO_API_EXPORT void remove_custom_data(io_ref_t custom_data, io_size_t index) {
    if (io_component_custom_data != nullptr) {
        io_component_custom_data->remove(custom_data, index);
    }
    else {
        io_logging->log_error("Custom data component interface is not available.");
    }
}

// Provides access to the character controller system
IO_API_EXPORT io_ref_t character_controller_for_entity(io_ref_t entity) {
    return io_component_character_controller->base.get_component_for_entity(entity);
}

IO_API_EXPORT void move(io_ref_t controller, io_vec3_t move_vector) {
    io_component_character_controller->move(controller, move_vector);
}

IO_API_EXPORT io_bool_t is_grounded(io_ref_t controller) {
    return io_component_character_controller->is_grounded(controller);
}

IO_API_EXPORT io_bool_t is_colliding_sides(io_ref_t controller) {
    return io_component_character_controller->is_colliding_sides(controller);
}

IO_API_EXPORT io_bool_t is_colliding_up(io_ref_t controller) {
    return io_component_character_controller->is_colliding_up(controller);
}

IO_API_EXPORT io_vec3_t get_foot_position(io_ref_t controller) {
    return io_component_character_controller->get_foot_position(controller);
}

// Provides access to the flipbook animation system
IO_API_EXPORT io_ref_t flipbook_animaiton_for_entity(io_ref_t entity) {
	return io_component_flipbook_animation->base.get_component_for_entity(entity);
}

IO_API_EXPORT void play_flipbook(io_ref_t flipbook) {
	io_component_flipbook_animation->play(flipbook);
}

IO_API_EXPORT void stop_flipbook(io_ref_t flipbook) {
	io_component_flipbook_animation->stop(flipbook);
}

// Provides access to the camera controller system
IO_API_EXPORT io_ref_t camera_controller_for_entity(io_ref_t entity) {
    return io_component_camera_controller->base.get_component_for_entity(entity);
}

IO_API_EXPORT void set_target_node(io_ref_t controller, io_ref_t node) {
    io_component_camera_controller->set_target_node(controller, node);
}

IO_API_EXPORT void set_target_euler_angles(io_ref_t controller, io_vec3_t euler_angles) {
    io_component_camera_controller->set_target_euler_angles(controller, euler_angles);
}

IO_API_EXPORT io_vec3_t get_target_euler_angles(io_ref_t controller) {
    return io_component_camera_controller->get_target_euler_angles(controller);
}


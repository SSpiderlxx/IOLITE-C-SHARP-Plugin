using System;
using System.Diagnostics;
using System.Runtime.InteropServices;

namespace IOLITE_Library
{

    using io_size_t = System.UInt32;

    // Struct to represent a 3D vector
    public struct io_vec3_t
    {
        public float x;
        public float y;
        public float z;

        public io_vec3_t(float x, float y, float z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct io_vec4_t
    {
        public float x;
        public float y;
        public float z;
        public float w;

        public io_vec4_t(float x, float y, float z, float w)
        {
            this.x = x;
            this.y = y;
            this.z = z;
            this.w = w;
        }

        public override string ToString()
        {
            return $"({x}, {y}, {z}, {w})";
        }
    }

    public struct io_vec2_t
    {
        public float x;
        public float y;

        public io_vec2_t(float x, float y)
        {
            this.x = x;
            this.y = y;
        }
    }

    // Struct to represent an axis-aligned bounding box (AABB)
    public struct io_aabb_t
    {
        public io_vec3_t center;      // Center of the AABB
        public io_vec3_t half_extent; // Half of the size of the AABB

        public io_aabb_t(io_vec3_t center, io_vec3_t half_extent)
        {
            this.center = center;
            this.half_extent = half_extent;
        }

        // Method to check if a point is inside the AABB
        public bool Contains(io_vec3_t point)
        {
            return Math.Abs(point.x - center.x) <= half_extent.x &&
                   Math.Abs(point.y - center.y) <= half_extent.y &&
                   Math.Abs(point.z - center.z) <= half_extent.z;
        }

        // Method to check if this AABB intersects with another AABB
        public bool Intersects(io_aabb_t other)
        {
            return Math.Abs(center.x - other.center.x) <= (half_extent.x + other.half_extent.x) &&
                   Math.Abs(center.y - other.center.y) <= (half_extent.y + other.half_extent.y) &&
                   Math.Abs(center.z - other.center.z) <= (half_extent.z + other.half_extent.z);
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct io_quat_t
    {
        public float w;
        public float x;
        public float y;
        public float z;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct io_ref_type_id_t
    {
        public uint Value;

        public io_ref_type_id_t(uint value)
        {
            Value = value;
        }

        public override string ToString()
        {
            return Value.ToString();
        }

        public static implicit operator uint(io_ref_type_id_t typeId)
        {
            return typeId.Value;
        }

        public static implicit operator io_ref_type_id_t(uint value)
        {
            return new io_ref_type_id_t(value);
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct io_uuid_t
    {
        public ulong Value;

        public io_uuid_t(ulong value)
        {
            Value = value;
        }

        public override string ToString()
        {
            return Value.ToString("X");
        }

        public static implicit operator ulong(io_uuid_t uuid)
        {
            return uuid.Value;
        }

        public static implicit operator io_uuid_t(ulong value)
        {
            return new io_uuid_t(value);
        }
    }

    [StructLayout(LayoutKind.Sequential, Pack = 1)]
    public struct io_ref_t
    {
        public ushort id;
        public byte gen;
        public byte type;

        public static io_ref_t Invalid
        {
            get
            {
                return new io_ref_t
                {
                    id = 0xFFFF,
                    gen = 0xFF,
                    type = 0xFF
                };
            }
        }

        public bool IsValid
        {
            get
            {
                return id != 0xFFFF && gen != 0xFF;
            }
        }

        public bool Equals(io_ref_t other)
        {
            return id == other.id && gen == other.gen && type == other.type;
        }

        public override bool Equals(object? obj)
        {
            if (obj is io_ref_t other)
            {
                return Equals(other);
            }
            return false;
        }

        public override int GetHashCode()
        {
            return HashCode.Combine(id, gen, type);
        }

        public static bool operator ==(io_ref_t left, io_ref_t right)
        {
            return left.Equals(right);
        }

        public static bool operator !=(io_ref_t left, io_ref_t right)
        {
            return !(left == right);
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct io_sphere_t
    {
        public io_vec3_t center;
        public float radius;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct io_name_t
    {
        public uint hash;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct io_variant_t
    {
        public io_name_t type;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
        public uint[] data;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct io_animation_system_animation_desc_t
    {
        public string animation_name;

        public float play_speed;
        public float bend_weight;
        public float blend_in_out_duration;
        public float priority;

        public float delay;

        public bool looping;
        public bool restore_when_finished;
    }

    public struct io_handle64_t
    {
        public ulong Internal { get; set; }

        public IoHandle64(ulong internalValue)
        {
            Internal = internalValue;
        }

        public static IoHandle64 Invalid => new IoHandle64(ulong.MaxValue);

        public bool IsValid => Internal != ulong.MaxValue;
    }

    public enum io_input_key_state
    {
        Released,
        Pressed,
        Clicked
    }

    public enum io_input_key
    {
        Up,
        Down,
        Left,
        Right,
        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,
        Key0,
        Key1,
        Key2,
        Key3,
        Key4,
        Key5,
        Key6,
        Key7,
        Key8,
        Key9,
        F1,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,
        Del,
        Backspace,
        Tab,
        MouseLeft,
        MouseRight,
        MouseMiddle,
        Shift,
        Alt,
        Ctrl,
        Space,
        Escape,
        Return,
        NumPlus,
        NumMinus,
        Num0,
        Num1,
        Num2,
        Num3,
        Num4,
        Num5,
        Num6,
        Num7,
        Num8,
        Num9,
        ControllerButtonA,
        ControllerButtonY,
        ControllerButtonB,
        ControllerButtonX,
        Any,
        Invalid,
        NumKeys
    }

    public enum io_input_axis : byte
    {
        LeftX,
        LeftY,
        RightX,
        RightY,
        TriggerLeft,
        TriggerRight,
        Invalid
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct io_physics_overlap_result_t
    {
        [MarshalAs(UnmanagedType.U1)]
        public bool hit;

        public io_ref_t entity;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct io_physics_raycast_result_t
    {
        [MarshalAs(UnmanagedType.U1)]
        public bool hit;

        public float distance;
        public io_vec3_t position;
        public io_vec3_t normal;

        public io_ref_t entity;
    }

    public enum io_ui_text_align_horizontal
    {
        Left = 0,   // io_ui_text_align_horizontal_left
        Center = 1, // io_ui_text_align_horizontal_center
        Right = 2   // io_ui_text_align_horizontal_right
    }

    public enum io_ui_text_align_vertical
    {
        Top = 0,    // io_ui_text_align_vertical_top
        Center = 1, // io_ui_text_align_vertical_center
        Bottom = 2  // io_ui_text_align_vertical_bottom
    }

    [Flags]
    public enum io_ui_text_flag
    {
        None = 0,
        Wrap = 0x01 // io_ui_text_flag_wrap
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct io_ui_rect_t
    {
        public io_vec2_t pos;
        public io_vec2_t extent;

        public io_ui_rect_t(io_vec2_t pos, io_vec2_t extent)
        {
            this.pos = pos;
            this.extent = extent;
        }

        public override string ToString()
        {
            return $"Pos: {pos}, Extent: {extent}";
        }
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct io_ui_anchor_t
    {
        public float anchor;
        public float offset;

        public io_ui_anchor_t(float anchor, float offset)
        {
            this.anchor = anchor;
            this.offset = offset;
        }

        public override string ToString()
        {
            return $"Anchor: {anchor}, Offset: {offset}";
        }
    }

    public enum io_ui_anchor_preset
    {
        FullRect,       // io_ui_anchor_preset_full_rect
        TopLeft,        // io_ui_anchor_preset_top_left
        TopRight,       // io_ui_anchor_preset_top_right
        BottomRight,    // io_ui_anchor_preset_bottom_right
        BottomLeft,     // io_ui_anchor_preset_bottom_left
        CenterLeft,     // io_ui_anchor_preset_center_left
        CenterTop,      // io_ui_anchor_preset_center_top
        CenterRight,    // io_ui_anchor_preset_center_right
        CenterBottom,   // io_ui_anchor_preset_center_bottom
        Center          // io_ui_anchor_preset_center
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct io_ui_anchor_offsets_t
    {
        public float left;
        public float right;
        public float top;
        public float bottom;

        public io_ui_anchor_offsets_t(float left, float right, float top, float bottom)
        {
            this.left = left;
            this.right = right;
            this.top = top;
            this.bottom = bottom;
        }

        public override string ToString()
        {
            return $"Left: {left}, Right: {right}, Top: {top}, Bottom: {bottom}";
        }
    }

    public enum io_ui_aspect_mode
    {
        Keep = 0 // io_ui_aspect_mode_keep
    }

    public enum io_ui_style_var
    {
        TextColor,            // io_ui_style_var_text_color
        TextOutlineColor,     // io_ui_style_var_text_outline_color
        TextOutline,          // io_ui_style_var_text_outline
        RectRounding,         // io_ui_style_var_rect_rounding
        DrawOutline,          // io_ui_style_var_draw_outline
        Alpha                 // io_ui_style_var_alpha
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct io_pathfinding_path_settings_t
    {
        public uint find_walkable_cell_range;
        public float capsule_radius;
        public float capsule_half_height;
        public float step_height;
        public float cell_size;
        public uint num_max_steps;
        public uint group_mask;
    }

    // Provides access to the filesystem
    public static class FileSystem
    {
        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        private static extern bool load_file_from_data_source(
            [MarshalAs(UnmanagedType.LPStr)] string filepath,
            out IntPtr data,
            out uint dataLength);

        public static bool LoadFileFromDataSource(string filepath, out byte[] data)
        {
            data = null;
            IntPtr dataPtr;
            uint dataLength;

            bool result = load_file_from_data_source(filepath, out dataPtr, out dataLength);

            if (result && dataLength > 0 && dataPtr != IntPtr.Zero)
            {
                data = new byte[dataLength];
                Marshal.Copy(dataPtr, data, 0, (int)dataLength);
                // Free the unmanaged memory if necessary
                // Marshal.FreeHGlobal(dataPtr); // Uncomment if the unmanaged memory needs to be freed
                return true;
            }
            else
            {
                return false;
            }
        }

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        private static extern bool create_or_retrieve_user_directory(
            [MarshalAs(UnmanagedType.LPStr)] string subdirectory,
            [MarshalAs(UnmanagedType.LPStr)] out IntPtr directoryPath);

        public static bool CreateOrRetrieveUserDirectory(string subdirectory, out string directoryPath)
        {
            directoryPath = null;
            IntPtr pathPtr;

            bool result = create_or_retrieve_user_directory(subdirectory, out pathPtr);

            if (result && pathPtr != IntPtr.Zero)
            {
                directoryPath = Marshal.PtrToStringAnsi(pathPtr);
                // Free the unmanaged string if necessary
                // Marshal.FreeHGlobal(pathPtr); // Uncomment if the unmanaged memory needs to be freed
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    // Provides access to the logging subsystem
    public static class Logging
    {
        [DllImport("iolite_api.dll")]
        public static extern void log_warning(string msg);

        [DllImport("iolite_api.dll")]
        public static extern void log_error(string msg);

        [DllImport("iolite_api.dll")]
        public static extern void log_info(string msg);
    }

    // Provides access to the editor
    public static class Editor
    {
        [DllImport("iolite_api.dll")]
        public static extern void select_node(io_ref_t node);

        [DllImport("iolite_api.dll")]
        public static extern io_ref_t get_first_selected_node();

        [DllImport("iolite_api.dll")]
        public static extern io_ref_t get_first_selected_entity();
    }

    // Provides access to the world subsystem
    public static class World
    {
        [DllImport("iolite_api.dll")]
        public static extern io_ref_t get_root_node();

        [DllImport("iolite_api.dll")]
        public static extern void load_world(string name);

        [DllImport("iolite_api.dll")]
        public static extern void save_world(string name);

        [DllImport("iolite_api.dll")]
        public static extern io_ref_t spawn_prefab(string name);

        [DllImport("iolite_api.dll")]
        public static extern io_ref_t get_active_camera();

        [DllImport("iolite_api.dll")]
        public static extern float get_current_time_factor();
    }

    // Provides access to node components
    public static class Node
    {
        [DllImport("iolite_api.dll")]
        public static extern io_ref_t get_node_for_entity(io_ref_t entity);

        [DllImport("iolite_api.dll")]
        public static extern io_ref_t create_node(string name);

        [DllImport("iolite_api.dll")]
        public static extern io_ref_t create_node_with_parent(string name, io_ref_t parent, bool ignore_parent);

        [DllImport("iolite_api.dll")]
        public static extern void attach_node(io_ref_t parent, io_ref_t child, bool ignore_parent);

        [DllImport("iolite_api.dll")]
        public static extern int get_node_depth(io_ref_t node);

        [DllImport("iolite_api.dll")]
        public static extern io_ref_t get_node_first_child(io_ref_t node);

        [DllImport("iolite_api.dll")]
        public static extern io_ref_t get_node_next_sibling(io_ref_t node);

        [DllImport("iolite_api.dll")]
        public static extern io_ref_t get_node_prev_sibling(io_ref_t node);

        [DllImport("iolite_api.dll")]
        public static extern io_aabb_t get_node_local_bounds(io_ref_t node);

        [DllImport("iolite_api.dll")]
        public static extern io_aabb_t get_node_world_bounds(io_ref_t node);

        [DllImport("iolite_api.dll")]
        public static extern void set_hidden(io_ref_t node, bool hidden);

        [DllImport("iolite_api.dll")]
        public static extern bool is_hidden(io_ref_t node);

        [DllImport("iolite_api.dll")]
        public static extern void set_node_world_position(io_ref_t node, io_vec3_t pos);

        [DllImport("iolite_api.dll")]
        public static extern io_vec3_t get_node_world_position(io_ref_t node);

        [DllImport("iolite_api.dll")]
        public static extern void set_node_size(io_ref_t node, io_vec3_t size);

        [DllImport("iolite_api.dll")]
        public static extern io_vec3_t get_node_size(io_ref_t node);

        [DllImport("iolite_api.dll")]
        public static extern void set_node_world_size(io_ref_t node, io_vec3_t size);

        [DllImport("iolite_api.dll")]
        public static extern io_vec3_t get_node_world_size(io_ref_t node);

        [DllImport("iolite_api.dll")]
        public static extern void set_node_orientation(io_ref_t node, io_quat_t orient);

        [DllImport("iolite_api.dll")]
        public static extern io_quat_t get_node_orientation(io_ref_t node);

        [DllImport("iolite_api.dll")]
        public static extern void set_node_world_orientation(io_ref_t node, io_quat_t orient);

        [DllImport("iolite_api.dll")]
        public static extern io_quat_t get_node_world_orientation(io_ref_t node);

        [DllImport("iolite_api.dll")]
        public static extern io_vec3_t to_local_space(io_ref_t node, io_vec3_t pos);

        [DllImport("iolite_api.dll")]
        public static extern io_vec3_t to_local_space_direction(io_ref_t node, io_vec3_t dir);

        [DllImport("iolite_api.dll")]
        public static extern io_vec3_t to_world_space(io_ref_t node, io_vec3_t pos);

        [DllImport("iolite_api.dll")]
        public static extern io_vec3_t to_world_space_direction(io_ref_t node, io_vec3_t dir);

        [DllImport("iolite_api.dll")]
        public static extern void update_transforms(io_ref_t node);

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void update_transforms_jobified([MarshalAs(UnmanagedType.LPArray)] io_ref_t[] nodes);

        // Managed wrappers for intersect functions
        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void intersect_point(
            io_vec3_t point,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] io_ref_t[] nodes,
            ulong nodes_length,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 4)] io_ref_t[] intersecting_nodes,
            ref ulong intersecting_nodes_length,
            bool use_global_bounds);

        public static io_ref_t[] IntersectPoint(io_vec3_t point, io_ref_t[] nodes, bool useGlobalBounds)
        {
            ulong intersectingNodesLength = (ulong)nodes.Length;
            io_ref_t[] intersectingNodes = new io_ref_t[nodes.Length];

            intersect_point(point, nodes, (ulong)nodes.Length, intersectingNodes, ref intersectingNodesLength, useGlobalBounds);

            Array.Resize(ref intersectingNodes, (int)intersectingNodesLength);
            return intersectingNodes;
        }

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void intersect_aabb(
            io_aabb_t aabb,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] io_ref_t[] nodes,
            ulong nodes_length,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 4)] io_ref_t[] intersecting_nodes,
            ref ulong intersecting_nodes_length,
            bool use_global_bounds);

        public static io_ref_t[] IntersectAABB(io_aabb_t aabb, io_ref_t[] nodes, bool useGlobalBounds)
        {
            ulong intersectingNodesLength = (ulong)nodes.Length;
            io_ref_t[] intersectingNodes = new io_ref_t[nodes.Length];

            intersect_aabb(aabb, nodes, (ulong)nodes.Length, intersectingNodes, ref intersectingNodesLength, useGlobalBounds);

            Array.Resize(ref intersectingNodes, (int)intersectingNodesLength);
            return intersectingNodes;
        }

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void intersect_sphere(
            io_sphere_t sphere,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] io_ref_t[] nodes,
            ulong nodes_length,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 4)] io_ref_t[] intersecting_nodes,
            ref ulong intersecting_nodes_length,
            bool use_global_bounds);

        public static io_ref_t[] IntersectSphere(io_sphere_t sphere, io_ref_t[] nodes, bool useGlobalBounds)
        {
            ulong intersectingNodesLength = (ulong)nodes.Length;
            io_ref_t[] intersectingNodes = new io_ref_t[nodes.Length];

            intersect_sphere(sphere, nodes, (ulong)nodes.Length, intersectingNodes, ref intersectingNodesLength, useGlobalBounds);

            Array.Resize(ref intersectingNodes, (int)intersectingNodesLength);
            return intersectingNodes;
        }
    }

    // Provides access to tag components
    public static class Tag
    {
        [DllImport("iolite_api.dll")]
        public static extern io_ref_t component_tag_for_entity(io_ref_t entity);

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void find_entities_with_tag(
            string tag,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] io_ref_t[] entities,
            ref ulong entities_length);

        public static io_ref_t[] FindEntitiesWithTag(string tag)
        {
            ulong entitiesLength = 1024;
            io_ref_t[] entities = new io_ref_t[entitiesLength];

            find_entities_with_tag(tag, entities, ref entitiesLength);

            Array.Resize(ref entities, (int)entitiesLength);
            return entities;
        }

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void get_tags(
            io_ref_t tagComponent,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] io_name_t[] tags,
            ref ulong tags_length);

        public static io_name_t[] GetTags(io_ref_t tagComponent)
        {
            ulong tagsLength = 1024;
            io_name_t[] tags = new io_name_t[tagsLength];

            get_tags(tagComponent, tags, ref tagsLength);

            Array.Resize(ref tags, (int)tagsLength);
            return tags;
        }

        [DllImport("iolite_api.dll")]
        public static extern void add_tag(io_ref_t entity, string tag);

        [DllImport("iolite_api.dll")]
        public static extern void remove_tag(io_ref_t entity, string tag);
    }

    // Provides access to the entity component
    public static class Entity
    {
        [DllImport("iolite_api.dll")]
        public static extern io_ref_type_id_t get_entity_type_id();

        [DllImport("iolite_api.dll")]
        public static extern bool is_alive(io_ref_t entity);

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.StdCall)]
        private static extern IntPtr get_name(io_ref_t entity);

        public static string GetName(io_ref_t entity)
        {
            IntPtr ptr = get_name(entity);
            return Marshal.PtrToStringAnsi(ptr);
        }

        [DllImport("iolite_api.dll")]
        public static extern io_uuid_t get_uuid(io_ref_t entity);

        [DllImport("iolite_api.dll")]
        public static extern io_ref_t find_first_entity_with_name(string name);

        [DllImport("iolite_api.dll")]
        public static extern io_ref_t find_entity_with_uuid(io_uuid_t uuid);

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void find_entities_with_name(
            string name,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] io_ref_t[] entities,
            ref ulong entities_length);

        public static io_ref_t[] FindEntitiesWithName(string name)
        {
            ulong entitiesLength = 1024;
            io_ref_t[] entities = new io_ref_t[entitiesLength];

            find_entities_with_name(name, entities, ref entitiesLength);

            Array.Resize(ref entities, (int)entitiesLength);
            return entities;
        }

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void find_entities_with_component(
            string componentTypeName,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] io_ref_t[] entities,
            ref ulong entities_length);

        public static io_ref_t[] FindEntitiesWithComponent(string componentTypeName)
        {
            ulong entitiesLength = 1024;
            io_ref_t[] entities = new io_ref_t[entitiesLength];

            find_entities_with_component(componentTypeName, entities, ref entitiesLength);

            Array.Resize(ref entities, (int)entitiesLength);
            return entities;
        }
    }

    // Provides access to the input system
    public static class Input
    {
        [DllImport("iolite_api.dll")]
        public static extern io_input_key_state get_key_state(io_input_key key);

        [DllImport("iolite_api.dll")]
        public static extern float get_axis_state(io_input_axis axis);

        [DllImport("iolite_api.dll")]
        public static extern io_vec2_t get_mouse_pos();

        [DllImport("iolite_api.dll")]
        public static extern io_vec2_t get_mouse_pos_viewport();

        [DllImport("iolite_api.dll")]
        public static extern io_vec2_t get_mouse_pos_relative();

        [DllImport("iolite_api.dll")]
        public static extern void request_mouse_cursor();
    }

    // Provides access to the animation system
    public static class Animation
    {
        [DllImport("iolite_api.dll")]
        public static extern void play_animation(io_ref_t node, io_animation_system_animation_desc_t desc);

        [DllImport("iolite_api.dll")]
        public static extern void stop_animation(io_ref_t node, string animation_name);

        [DllImport("iolite_api.dll")]
        public static extern void stop_all_animations(io_ref_t node);

        [DllImport("iolite_api.dll")]
        public static extern void pause_animation(io_handle64_t instance);

        [DllImport("iolite_api.dll")]
        public static extern void resume_animation(io_handle64_t instance);

        [DllImport("iolite_api.dll")]
        public static extern bool is_finished(io_handle64_t instance);

        [DllImport("iolite_api.dll")]
        public static extern void blend_in_out(io_handle64_t instance, float target_blend_weight, float duration, float delay, bool stop_animation);

        [DllImport("iolite_api.dll")]
        public static extern float get_blend_weight(io_handle64_t instance);

        [DllImport("iolite_api.dll")]
        public static extern void set_blend_weight(io_handle64_t instance, float weight);

        [DllImport("iolite_api.dll")]
        public static extern float get_play_speed(io_handle64_t instance);

        [DllImport("iolite_api.dll")]
        public static extern void set_play_speed(io_handle64_t instance, float speed);

        [DllImport("iolite_api.dll")]
        public static extern float get_timeline_position(io_handle64_t instance);

        [DllImport("iolite_api.dll")]
        public static extern void set_timeline_position(io_handle64_t instance, float position);
    }

    // Provides access to the physics system
    public static class Physics
    {
        [DllImport("iolite_api.dll")]
        public static extern io_physics_overlap_result_t overlap_sphere(io_vec3_t position, float radius, int group_mask);

        [DllImport("iolite_api.dll")]
        public static extern io_physics_raycast_result_t sweep_sphere(io_vec3_t position, float radius, io_vec3_t direction, float distance, int group_mask);

        [DllImport("iolite_api.dll")]
        public static extern io_physics_raycast_result_t raycast(io_vec3_t origin, io_vec3_t direction, float distance, int group_mask);
    }

    // Provides access to the UI system
    public static class UI
    {
        [DllImport("iolite_api.dll")]
        public static extern void draw_rect(io_vec4_t color);

        [DllImport("iolite_api.dll")]
        public static extern void draw_circle(io_vec4_t color);

        [DllImport("iolite_api.dll")]
        public static extern void draw_ngon(io_vec4_t color, uint sides);

        [DllImport("iolite_api.dll")]
        public static extern void draw_image(string name, io_vec4_t tint);

        [DllImport("iolite_api.dll")]
        public static extern void draw_text(string text, int align_horizontal, int align_vertical, int flags);

        [DllImport("iolite_api.dll")]
        public static extern io_ui_rect_t calc_text_bounds(string text, int align_horizontal, int align_vertical, int flags);

        [DllImport("iolite_api.dll")]
        public static extern io_ui_rect_t get_last_text_bounds();

        [DllImport("iolite_api.dll")]
        public static extern void push_transform(io_ui_anchor_t left, io_ui_anchor_t right, io_ui_anchor_t top, io_ui_anchor_t bottom, float rotation);

        [DllImport("iolite_api.dll")]
        public static extern void push_transform_preset(io_ui_anchor_preset preset, io_ui_anchor_offsets_t offsets, float rotation);

        [DllImport("iolite_api.dll")]
        public static extern void pop_transform();

        [DllImport("iolite_api.dll")]
        public static extern void push_scale_offset_for_base_size(io_vec2_t base_size, io_ui_aspect_mode aspect_mode);

        [DllImport("iolite_api.dll")]
        public static extern void push_scale_offset(float scale, io_vec2_t offset);

        [DllImport("iolite_api.dll")]
        public static extern void pop_scale_offset();

        [DllImport("iolite_api.dll")]
        public static extern void push_style_var_float(io_ui_style_var var, float value);

        [DllImport("iolite_api.dll")]
        public static extern void push_style_var_vec4(io_ui_style_var var, io_vec4_t value);

        [DllImport("iolite_api.dll")]
        public static extern void pop_style_var();

        [DllImport("iolite_api.dll")]
        public static extern void clip_children();

        [DllImport("iolite_api.dll")]
        public static extern void push_font_size(float size);

        [DllImport("iolite_api.dll")]
        public static extern void pop_font_size();

        [DllImport("iolite_api.dll")]
        public static extern bool intersects(io_vec2_t position);
    }

    // Provides access to the sound system
    public static class Sound
    {
        [DllImport("iolite_api.dll")]
        public static extern io_handle64_t play_sound_effect(string effect_name);

        [DllImport("iolite_api.dll")]
        public static extern void stop_sound_effect(io_handle64_t effect_handle);

        [DllImport("iolite_api.dll")]
        public static extern void set_sound_position(io_handle64_t effect_handle, io_vec3_t position);

        [DllImport("iolite_api.dll")]
        private static extern void get_audio_spectrum(out IntPtr spectrumData, out uint spectrumLength);

        public static float[] GetAudioSpectrum()
        {
            get_audio_spectrum(out IntPtr spectrumPtr, out uint spectrumLength);
            if (spectrumLength == 0 || spectrumPtr == IntPtr.Zero)
                return new float[0];

            float[] spectrum = new float[spectrumLength];
            Marshal.Copy(spectrumPtr, spectrum, 0, (int)spectrumLength);
            return spectrum;
        }
    }

    // Provides access to the pathfinding system
    public static class Pathfinding
    {
        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern io_handle16_t find_path(io_vec3_t start, io_vec3_t end, ref io_pathfinding_path_settings_t settings);

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool is_valid(io_handle16_t path_handle);

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void reset_path(io_handle16_t path_handle);

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void destroy_path(io_handle16_t path_handle);

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool is_path_found(io_handle16_t path_handle);

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        public static extern bool get_next_position_on_path(io_handle16_t path_handle, out io_vec3_t next_position);

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void draw_path(io_handle16_t path_handle, io_vec4_t color, [MarshalAs(UnmanagedType.I1)] bool always_in_front);

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void draw_debug_geometry(io_handle16_t path_handle, [MarshalAs(UnmanagedType.I1)] bool always_in_front);
    }

    // Provides access to custom data components
    public static class CustomDataComponent
    {
        [DllImport("iolite_api.dll")]
        public static extern io_ref_t get_custom_data_component_for_entity(io_ref_t entity);

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern io_variant_t get_custom_data(io_ref_t custom_data, ulong index);

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void set_custom_data(io_ref_t custom_data, ulong index, io_variant_t value);

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void add_custom_data(io_ref_t custom_data, io_variant_t value);

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void remove_custom_data(io_ref_t custom_data, ulong index);
    }

    public static class CharacterController
    {
        [DllImport("iolite_api.dll")]
        public static extern io_ref_t character_controller_for_entity(io_ref_t entity);

        [DllImport("iolite_api.dll")]
        public static extern void move(io_ref_t controller, io_vec3_t move_vector);

        [DllImport("iolite_api.dll")]
        public static extern bool is_grounded(io_ref_t controller);

        [DllImport("iolite_api.dll")]
        public static extern bool is_colliding_sides(io_ref_t controller);

        [DllImport("iolite_api.dll")]
        public static extern is_colliding_up(io_ref_t controller);

        [DllImport("iolite_api.dll")]
        public static extern io_vec3_t get_foot_position(io_ref_t controller);
    }

    // Main class using the organized API functions
    public class Class1
    {
        public static int Run(IntPtr arg, int argLength)
        {
            Logging.log_warning("Hello from .NET!");
            return 0;
        }

        public static void On_Activate()
        {
            Logging.log_warning("On_Activate");
        }

        public static void On_Tick(float delta_t)
        {
            Logging.log_warning("On_Tick");

            // Move node named "deer" to the right
            io_ref_t deer = Entity.find_first_entity_with_name("deer");

            Logging.log_warning(deer.id.ToString() + deer.type.ToString());

            Logging.log_info(Entity.GetName(deer));
            io_ref_t node = Node.get_node_for_entity(deer);

            io_vec3_t pos = Node.get_node_world_position(node);

            pos.x += 0.1f;
            Node.set_node_world_position(node, pos);
        }
    }


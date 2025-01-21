using System;
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

    public class Class1
    {

        // Provides access to the logging subsystem
        [DllImport("iolite_api.dll")]
        public static extern void log_warning(string msg);

        [DllImport("iolite_api.dll")]
        public static extern void log_error(string msg);

        [DllImport("iolite_api.dll")]
        public static extern void log_info(string msg);

        // Provides access to the editor
        [DllImport("iolite_api.dll")]
        public static extern void select_node(io_ref_t node);

        [DllImport("iolite_api.dll")]
        public static extern io_ref_t get_first_selected_node();

        [DllImport("iolite_api.dll")]
        public static extern io_ref_t get_first_selected_entity();

        // Provides access to the world subsystem
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

        // Provides access to node components
        [DllImport("iolite_api.dll")]
        public static extern io_ref_t create_node(string name);

        [DllImport("iolite_api.dll")]
        public static extern io_ref_t create_node_with_parent(string name,  io_ref_t parent, bool ignore_parent);

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

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void intersect_point(
            io_vec3_t point,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] io_ref_t[] nodes,
            ulong nodes_length,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 4)] io_ref_t[] intersecting_nodes,
            ref ulong intersecting_nodes_length,
            bool use_global_bounds
        );

        public static io_ref_t[] CallIntersectPoint(
            io_vec3_t point,
            io_ref_t[] nodes,
            bool useGlobalBounds)
            {
                // Validate input
                if (nodes == null || nodes.Length == 0)
                {
                    throw new ArgumentException("The nodes array must not be null or empty.");
                }

                // Prepare the output buffer with a size equal to the input nodes array
                ulong intersectingNodesLength = (ulong)nodes.Length; // Maximum possible size
                io_ref_t[] intersectingNodes = new io_ref_t[nodes.Length];

                // Call the native function
                intersect_point(point, nodes, (ulong)nodes.Length, intersectingNodes, ref intersectingNodesLength, useGlobalBounds);

                // Resize the output array to the actual number of intersecting nodes
                Array.Resize(ref intersectingNodes, (int)intersectingNodesLength);

                // Return the intersecting nodes
                return intersectingNodes;
            }

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void intersect_aabb(
            io_aabb_t aabb,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] io_ref_t[] nodes,
            ulong nodes_length,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 4)] io_ref_t[] intersecting_nodes,
            ref ulong intersecting_nodes_length,
            bool use_global_bounds
        );

        public static io_ref_t[] CallIntersectAABB(
            io_aabb_t aabb,
            io_ref_t[] nodes,
            bool useGlobalBounds){
                if (nodes == null || nodes.Length == 0)
                {
                    throw new ArgumentException("The nodes array must not be null or empty.");
                }

                // Prepare output buffer
                ulong intersectingNodesLength = (ulong)nodes.Length; // Maximum possible size
                io_ref_t[] intersectingNodes = new io_ref_t[nodes.Length];

                // Call the native function
                intersect_aabb(aabb, nodes, (ulong)nodes.Length, intersectingNodes, ref intersectingNodesLength, useGlobalBounds);

                // Resize the output array to match the actual number of intersecting nodes
                Array.Resize(ref intersectingNodes, (int)intersectingNodesLength);

                return intersectingNodes;
            }

        [DllImport("iolite_api.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void intersect_sphere(
            io_sphere_t sphere,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] io_ref_t[] nodes,
            ulong nodes_length,
            [MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 4)] io_ref_t[] intersecting_nodes,
            ref ulong intersecting_nodes_length,
            bool use_global_bounds
        );

        public static io_ref_t[] CallIntersectSphere(
            io_sphere_t sphere,
            io_ref_t[] nodes,
            bool useGlobalBounds)
                {
                    // Validate input
                    if (nodes == null || nodes.Length == 0)
                    {
                        throw new ArgumentException("The nodes array must not be null or empty.");
                    }

                    // Prepare the output buffer with a size equal to the input nodes array
                    ulong intersectingNodesLength = (ulong)nodes.Length; // Maximum possible size
                    io_ref_t[] intersectingNodes = new io_ref_t[nodes.Length];

                    // Call the native function
                    intersect_sphere(sphere, nodes, (ulong)nodes.Length, intersectingNodes, ref intersectingNodesLength, useGlobalBounds);

                    // Resize the output array to the actual number of intersecting nodes
                    Array.Resize(ref intersectingNodes, (int)intersectingNodesLength);

                    // Return the intersecting nodes
                    return intersectingNodes;
                }

        public static int Run(IntPtr arg, int argLength)
        {
            log_warning($"Hello from .NET!");
            return 0;  // Return an integer as expected by the delegate signature
        }

        //public static void On_Load();

        public delegate void On_Tick_Delegate(float delta_t);
        public static void On_Tick(float delta_t){
            log_warning("On_Tick");
            log_warning(get_active_camera().IsValid.ToString());
        }
    }
}

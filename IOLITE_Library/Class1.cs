using System;
using System.Runtime.InteropServices;

namespace IOLITE_Library
{
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

        public override bool Equals(object obj)
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
        public static extern float get_current_time_factor();

        public static int Run(IntPtr arg, int argLength)
        {
            log_warning($"Hello from .NET!");
            return 0;  // Return an integer as expected by the delegate signature
        }

        //public static void On_Load();

        public delegate void On_Tick_Delegate(float delta_t);
        public static void On_Tick(float delta_t){
            log_warning("On_Tick");
        }
    }
}

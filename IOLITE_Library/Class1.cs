using System;
using System.Runtime.InteropServices;

namespace IOLITE_Library
{
    public class Class1
    {
        [DllImport("iolite_api.dll")]
        public static extern void log_warning(string msg);

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

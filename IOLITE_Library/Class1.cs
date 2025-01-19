using System;

namespace IOLITE_Library
{
    public class Class1
    {
        public static int Run(IntPtr arg, int argLength)
        {
            Console.WriteLine($"Hello from .NET!");
            return 0;  // Return an integer as expected by the delegate signature
        }
    }
}

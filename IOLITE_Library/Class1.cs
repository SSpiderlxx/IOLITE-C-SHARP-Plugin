using IOLITE_Library.Systems;
using IOLITE_Library;

// Main class using the organized API functions=
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
        CharacterControllerScript.OnActivate();
    }

    public static void On_Tick(float delta_t)
    {
        Logging.log_warning("On_Tick");
        CharacterControllerScript.UpdateCharacter(delta_t);
    }
}


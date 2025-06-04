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


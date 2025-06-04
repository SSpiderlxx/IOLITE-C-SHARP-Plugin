using System;
using IOLITE_Library;
using IOLITE_Library.Systems;

public static class CharacterControllerScript
{
    private static io_vec3_t PlayerVelocity = new io_vec3_t(0.0f, 0.0f, 0.0f);
    private static float? TimeAirborne = null;
    private static bool Jumped = false;
    // private static io_handle64_t FootstepsSound = default; // Uncomment and implement if needed

    public static void OnActivate()
    {
        var player = Entity.find_first_entity_with_name("player");
        var player_node = Node.get_node_for_entity(player);
        var cam = Entity.find_first_entity_with_name("game_camera");
        var cam_ctrl = CameraController.camera_controller_for_entity(cam);

        Logging.log_info("OnActivate called for CharacterController script");

        CameraController.set_target_node(cam_ctrl, player_node);
        PlayerVelocity = new io_vec3_t(0.0f, 0.0f, 0.0f);
    }

    public static void OnDeactivate(io_ref_t entity)
    {
        // No-op for now
    }

    public static void UpdateCharacter(float delta_t)
    {
        var player = Entity.find_first_entity_with_name("player");
        var player_cct = CharacterController.character_controller_for_entity(player);
        var player_node = Node.get_node_for_entity(player);
        bool grounded = CharacterController.is_grounded(player_cct);

        // Handle ground checking
        if (!grounded)
        {
            if (!TimeAirborne.HasValue)
                TimeAirborne = 0.0f;
            TimeAirborne += delta_t;
        }
        else
        {
            TimeAirborne = 0.0f;
        }

        var cam = Entity.find_first_entity_with_name("game_camera");
        var cam_ctrl = CameraController.camera_controller_for_entity(cam);

        // Apply Gravity
        if (!grounded)
        {
            PlayerVelocity.y -= delta_t * 9.81f;
        }
        else if (PlayerVelocity.y < 0.0f)
        {
            PlayerVelocity.y *= 0.999f;
        }

        // Apply mouse movement
        var mouse_pos_rel = Input.get_mouse_pos_relative();
        var target_orientation = CameraController.get_target_euler_angles(cam_ctrl);
        target_orientation.x += mouse_pos_rel.y * 0.01f;
        target_orientation.y -= mouse_pos_rel.x * 0.01f;

        // WASD movement
        var mov_vec_local = new io_vec3_t(0.0f, 0.0f, 0.0f);
        if (Input.get_key_state(io_input_key.W) == io_input_key_state.Pressed)
            mov_vec_local.z += 1.0f;
        if (Input.get_key_state(io_input_key.S) == io_input_key_state.Pressed)
            mov_vec_local.z -= 1.0f;
        if (Input.get_key_state(io_input_key.A) == io_input_key_state.Pressed)
            mov_vec_local.x += 1.0f;
        if (Input.get_key_state(io_input_key.D) == io_input_key_state.Pressed)
            mov_vec_local.x -= 1.0f;

        float mov_vec_len = (float)Math.Sqrt(mov_vec_local.x * mov_vec_local.x + mov_vec_local.y * mov_vec_local.y + mov_vec_local.z * mov_vec_local.z);
        // Normalize and handle footsteps sound if needed
        // ...footsteps sound logic can be added here...

        // Apply speed
        float speed = 8.0f;
        mov_vec_local.x *= speed;
        mov_vec_local.y *= speed;
        mov_vec_local.z *= speed;

        // Rotate movement vector by camera yaw
        float yaw = target_orientation.y;
        float cosYaw = (float)Math.Cos(yaw);
        float sinYaw = (float)Math.Sin(yaw);
        var mov_vec_global = new io_vec3_t(
            mov_vec_local.x * cosYaw - mov_vec_local.z * sinYaw,
            0.0f,
            mov_vec_local.x * sinYaw + mov_vec_local.z * cosYaw
        );
        PlayerVelocity.x = mov_vec_global.x;
        PlayerVelocity.z = mov_vec_global.z;

        // Jumping
        if (TimeAirborne < 0.1f && Input.get_key_state(io_input_key.Space) == io_input_key_state.Pressed)
        {
            PlayerVelocity.y = 5.0f;
            Jumped = true;
        }
        else if (Input.get_key_state(io_input_key.Space) == io_input_key_state.Released)
        {
            Jumped = false;
        }

        // Update the camera controller
        CameraController.set_target_euler_angles(cam_ctrl, target_orientation);
        // Move the player
        CharacterController.move(player_cct, PlayerVelocity);
    }

    public static void Tick(float delta_t)
    {
        UpdateCharacter(delta_t);
    }
}
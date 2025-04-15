Iolite C-Sharp Plugin
=====================
The Iolite c# plugin is an ongoing project, which is still currently underdevelopment. It is designed to allow you to seamlessly access the iolite api use C#, it aims to allow users to interact with the API without having to understand C++. 

How it works
-------------
It currently works the same as mono game, where all code must be triggered by the main loop. This may change in the future, however the main focus as of now is getting most of the api accessable through C#.

How to setup
-------------
- Build the dotnethost.dll and iolite_api.dll using CMAKE.
- Place the two dll files inside the root folder of your Iolite project.
- Include both dll's as a plugin ( IOLITE_API.DLL should be initalized before the DOTNETHOST.DLL)
- Using thet iolite_libary .net 8 project write your code and when finished build the donet project as a dll and place it into the root folder of your iolite project.


Progress
------------

| API Name                            | Supported       |
|-------------------------------------|-----------------|
| IO_USER_TASK_API_NAME               | ✗               |
| IO_USER_DEBUG_VIEW_API_NAME         | ✗               |
| IO_USER_EDITOR_API_NAME             | ✗               |
| IO_USER_EDITOR_TOOL_API_NAME        | ✗               |
| IO_USER_DENOISER_API_NAME           | ✗               |
| IO_USER_EVENTS_API_NAME             | ✗               |
| IO_API_MANAGER_API_NAME             | ✗               |
| IO_BASE_API_NAME                    | ✗               |
| IO_LOGGING_API_NAME                 |   ✓             |
| IO_EDITOR_API_NAME                  |   ✓             |
| IO_CUSTOM_COMPONENTS_API_NAME       | ✗               |
| IO_CUSTOM_EVENT_STREAMS_API_NAME    | ✗               |
| IO_SETTINGS_API_NAME                | ✗               |
| IO_UI_API_NAME                      |   ✓             |
| IO_WORLD_API_NAME                   |   ✓             |
| IO_SAVE_DATA_API_NAME               | ✗               |
| IO_PARTICLE_SYSTEM_API_NAME         | ✗               |
| IO_INPUT_SYSTEM_API_NAME            |   ✓             |
| IO_ANIMATION_SYSTEM_API_NAME        |   ✓             |
| IO_PHYSICS_API_NAME                 |   ✓             |
| IO_DEBUG_GEOMETRY_API_NAME          | ✗               |
| IO_SOUND_API_NAME                   |   ✓             |
| IO_PATHFINDING_API_NAME             |   ✓             |
| IO_FILESYSTEM_API_NAME              |   ✓             |
| IO_ENTITY_API_NAME                  |   ✓             |
| IO_COMPONENT_NODE_API_NAME          |   ✓             |
| IO_COMPONENT_CUSTOM_DATA_API_NAME   |   ✓             |
| IO_COMPONENT_TAG_API_NAME           |   ✓             |
| IO_COMPONENT_FLIPBOOK_ANIMATION_API_NAME  |  ✓         |
| IO_COMPONENT_POST_EFFECT_VOLUME_API_NAME  | ✗         |
| IO_COMPONENT_CAMERA_API_NAME        | ✗               |
| IO_COMPONENT_LIGHT_API_NAME         | ✗               |
| IO_COMPONENT_VOXEL_SHAPE_API_NAME   | ✗               |
| IO_COMPONENT_VEHICLE_API_NAME       | ✗               |
| IO_COMPONENT_VEHICLE_WHEEL_API_NAME | ✗               |
| IO_COMPONENT_JOINT_API_NAME         | ✗               |
| IO_COMPONENT_CHARACTER_CONTROLLER_API_NAME |   ✓       |
| IO_COMPONENT_CAMERA_CONTROLLER_API_NAME  | ✗          |
| IO_COMPONENT_PARTICLE_API_NAME      | ✗               |
| IO_RESOURCE_PALETTE_API_NAME        | ✗               |
| IO_LOW_LEVEL_PHYSX_API_NAME         | ✗               |
| IO_LOW_LEVEL_IMGUI_API_NAME         | ✗               |
| IO_LOW_LEVEL_VULKAN_API_NAME        | ✗               |

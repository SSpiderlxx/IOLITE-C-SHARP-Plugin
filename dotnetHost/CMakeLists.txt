# Set the project name and minimum required CMake version
cmake_minimum_required(VERSION 3.12)
project(dotnetHost)

# Define the directory containing the .NET host files
set(PROJECT_DIR ${CMAKE_SOURCE_DIR}/dotnetHost)

# Define the path to the libraries
set(LIBS_DIR ${PROJECT_DIR}/libs)

# Define the header files
set(HEADER_FILES
    ${PROJECT_DIR}/inc/coreclr_delegates.h
    ${PROJECT_DIR}/inc/hostfxr.h
    ${PROJECT_DIR}/inc/nethost.h
    ${PROJECT_DIR}/inc/iolite_api.h
)

# Add source files
add_library(dotnetHost SHARED ${PROJECT_DIR}/dotnetHost.cpp ${HEADER_FILES})

# Set the C++ standard
set_property(TARGET dotnetHost PROPERTY CXX_STANDARD 20)

# Include directories for header files
target_include_directories(dotnetHost PRIVATE ${PROJECT_DIR}/inc)

# Link required libraries (nethost, kernel32/dl)
if(WIN32)
    # Link the nethost.lib library
    target_link_libraries(dotnetHost PRIVATE ${LIBS_DIR}/nethost.lib kernel32)
else()
    # Link libnethost.so on Linux/macOS
    target_link_libraries(dotnetHost PRIVATE nethost dl)
endif()

# Define export macros for different platforms
if(WIN32)
    target_compile_definitions(dotnetHost PRIVATE DOTNETHOST_EXPORTS)
else()
    target_compile_definitions(dotnetHost PRIVATE __DOTNETHOST_EXPORTS__)
endif()

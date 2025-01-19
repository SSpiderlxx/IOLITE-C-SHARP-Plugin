cmake_minimum_required(VERSION 3.12)
project(iolite_api)

# Define the directory containing the project files
set(PROJECT_DIR ${CMAKE_SOURCE_DIR}/iolite_api)

# Add source files (you don't need to list header files here)
add_library(iolite_api SHARED ${PROJECT_DIR}/iolite_api.cpp)

# Set the C++ standard
set_property(TARGET iolite_api PROPERTY CXX_STANDARD 20)

# Include directories for header files
target_include_directories(iolite_api PRIVATE ${PROJECT_DIR}/inc)

# Define export macros for different platforms
if(WIN32)
    target_compile_definitions(iolite_api PRIVATE IOLITE_API_EXPORTS)
else()
    target_compile_definitions(iolite_api PRIVATE IOLITE_API_EXPORTS)
endif()

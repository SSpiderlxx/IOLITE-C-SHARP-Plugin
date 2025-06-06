# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin"

# Include any dependencies generated for this target.
include iolite_api/CMakeFiles/iolite_api.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include iolite_api/CMakeFiles/iolite_api.dir/compiler_depend.make

# Include the progress variables for this target.
include iolite_api/CMakeFiles/iolite_api.dir/progress.make

# Include the compile flags for this target's objects.
include iolite_api/CMakeFiles/iolite_api.dir/flags.make

iolite_api/CMakeFiles/iolite_api.dir/iolite_api.cpp.o: iolite_api/CMakeFiles/iolite_api.dir/flags.make
iolite_api/CMakeFiles/iolite_api.dir/iolite_api.cpp.o: iolite_api/iolite_api.cpp
iolite_api/CMakeFiles/iolite_api.dir/iolite_api.cpp.o: iolite_api/CMakeFiles/iolite_api.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object iolite_api/CMakeFiles/iolite_api.dir/iolite_api.cpp.o"
	cd "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/iolite_api" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT iolite_api/CMakeFiles/iolite_api.dir/iolite_api.cpp.o -MF CMakeFiles/iolite_api.dir/iolite_api.cpp.o.d -o CMakeFiles/iolite_api.dir/iolite_api.cpp.o -c "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/iolite_api/iolite_api.cpp"

iolite_api/CMakeFiles/iolite_api.dir/iolite_api.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/iolite_api.dir/iolite_api.cpp.i"
	cd "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/iolite_api" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/iolite_api/iolite_api.cpp" > CMakeFiles/iolite_api.dir/iolite_api.cpp.i

iolite_api/CMakeFiles/iolite_api.dir/iolite_api.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/iolite_api.dir/iolite_api.cpp.s"
	cd "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/iolite_api" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/iolite_api/iolite_api.cpp" -o CMakeFiles/iolite_api.dir/iolite_api.cpp.s

# Object files for target iolite_api
iolite_api_OBJECTS = \
"CMakeFiles/iolite_api.dir/iolite_api.cpp.o"

# External object files for target iolite_api
iolite_api_EXTERNAL_OBJECTS =

iolite_api/libiolite_api.so: iolite_api/CMakeFiles/iolite_api.dir/iolite_api.cpp.o
iolite_api/libiolite_api.so: iolite_api/CMakeFiles/iolite_api.dir/build.make
iolite_api/libiolite_api.so: iolite_api/CMakeFiles/iolite_api.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libiolite_api.so"
	cd "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/iolite_api" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iolite_api.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
iolite_api/CMakeFiles/iolite_api.dir/build: iolite_api/libiolite_api.so
.PHONY : iolite_api/CMakeFiles/iolite_api.dir/build

iolite_api/CMakeFiles/iolite_api.dir/clean:
	cd "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/iolite_api" && $(CMAKE_COMMAND) -P CMakeFiles/iolite_api.dir/cmake_clean.cmake
.PHONY : iolite_api/CMakeFiles/iolite_api.dir/clean

iolite_api/CMakeFiles/iolite_api.dir/depend:
	cd "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin" "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/iolite_api" "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin" "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/iolite_api" "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/iolite_api/CMakeFiles/iolite_api.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : iolite_api/CMakeFiles/iolite_api.dir/depend


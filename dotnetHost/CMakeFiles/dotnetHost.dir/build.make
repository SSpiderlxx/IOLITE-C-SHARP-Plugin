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
include dotnetHost/CMakeFiles/dotnetHost.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include dotnetHost/CMakeFiles/dotnetHost.dir/compiler_depend.make

# Include the progress variables for this target.
include dotnetHost/CMakeFiles/dotnetHost.dir/progress.make

# Include the compile flags for this target's objects.
include dotnetHost/CMakeFiles/dotnetHost.dir/flags.make

dotnetHost/CMakeFiles/dotnetHost.dir/dotnetHost.cpp.o: dotnetHost/CMakeFiles/dotnetHost.dir/flags.make
dotnetHost/CMakeFiles/dotnetHost.dir/dotnetHost.cpp.o: dotnetHost/dotnetHost.cpp
dotnetHost/CMakeFiles/dotnetHost.dir/dotnetHost.cpp.o: dotnetHost/CMakeFiles/dotnetHost.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object dotnetHost/CMakeFiles/dotnetHost.dir/dotnetHost.cpp.o"
	cd "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/dotnetHost" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT dotnetHost/CMakeFiles/dotnetHost.dir/dotnetHost.cpp.o -MF CMakeFiles/dotnetHost.dir/dotnetHost.cpp.o.d -o CMakeFiles/dotnetHost.dir/dotnetHost.cpp.o -c "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/dotnetHost/dotnetHost.cpp"

dotnetHost/CMakeFiles/dotnetHost.dir/dotnetHost.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dotnetHost.dir/dotnetHost.cpp.i"
	cd "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/dotnetHost" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/dotnetHost/dotnetHost.cpp" > CMakeFiles/dotnetHost.dir/dotnetHost.cpp.i

dotnetHost/CMakeFiles/dotnetHost.dir/dotnetHost.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dotnetHost.dir/dotnetHost.cpp.s"
	cd "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/dotnetHost" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/dotnetHost/dotnetHost.cpp" -o CMakeFiles/dotnetHost.dir/dotnetHost.cpp.s

# Object files for target dotnetHost
dotnetHost_OBJECTS = \
"CMakeFiles/dotnetHost.dir/dotnetHost.cpp.o"

# External object files for target dotnetHost
dotnetHost_EXTERNAL_OBJECTS =

dotnetHost/libdotnetHost.so: dotnetHost/CMakeFiles/dotnetHost.dir/dotnetHost.cpp.o
dotnetHost/libdotnetHost.so: dotnetHost/CMakeFiles/dotnetHost.dir/build.make
dotnetHost/libdotnetHost.so: dotnetHost/CMakeFiles/dotnetHost.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libdotnetHost.so"
	cd "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/dotnetHost" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dotnetHost.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dotnetHost/CMakeFiles/dotnetHost.dir/build: dotnetHost/libdotnetHost.so
.PHONY : dotnetHost/CMakeFiles/dotnetHost.dir/build

dotnetHost/CMakeFiles/dotnetHost.dir/clean:
	cd "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/dotnetHost" && $(CMAKE_COMMAND) -P CMakeFiles/dotnetHost.dir/cmake_clean.cmake
.PHONY : dotnetHost/CMakeFiles/dotnetHost.dir/clean

dotnetHost/CMakeFiles/dotnetHost.dir/depend:
	cd "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin" "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/dotnetHost" "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin" "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/dotnetHost" "/home/leon/Documents/Iolite Projects/IOLITE-C-SHARP-Plugin/dotnetHost/CMakeFiles/dotnetHost.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : dotnetHost/CMakeFiles/dotnetHost.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/lucky/Downloads/clion-2020.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lucky/Downloads/clion-2020.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lucky/CLionProjects/session_27

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lucky/CLionProjects/session_27/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/session_27.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/session_27.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/session_27.dir/flags.make

CMakeFiles/session_27.dir/main.c.o: CMakeFiles/session_27.dir/flags.make
CMakeFiles/session_27.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucky/CLionProjects/session_27/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/session_27.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/session_27.dir/main.c.o   -c /home/lucky/CLionProjects/session_27/main.c

CMakeFiles/session_27.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/session_27.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lucky/CLionProjects/session_27/main.c > CMakeFiles/session_27.dir/main.c.i

CMakeFiles/session_27.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/session_27.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lucky/CLionProjects/session_27/main.c -o CMakeFiles/session_27.dir/main.c.s

# Object files for target session_27
session_27_OBJECTS = \
"CMakeFiles/session_27.dir/main.c.o"

# External object files for target session_27
session_27_EXTERNAL_OBJECTS =

session_27: CMakeFiles/session_27.dir/main.c.o
session_27: CMakeFiles/session_27.dir/build.make
session_27: CMakeFiles/session_27.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lucky/CLionProjects/session_27/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable session_27"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/session_27.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/session_27.dir/build: session_27

.PHONY : CMakeFiles/session_27.dir/build

CMakeFiles/session_27.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/session_27.dir/cmake_clean.cmake
.PHONY : CMakeFiles/session_27.dir/clean

CMakeFiles/session_27.dir/depend:
	cd /home/lucky/CLionProjects/session_27/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lucky/CLionProjects/session_27 /home/lucky/CLionProjects/session_27 /home/lucky/CLionProjects/session_27/cmake-build-debug /home/lucky/CLionProjects/session_27/cmake-build-debug /home/lucky/CLionProjects/session_27/cmake-build-debug/CMakeFiles/session_27.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/session_27.dir/depend


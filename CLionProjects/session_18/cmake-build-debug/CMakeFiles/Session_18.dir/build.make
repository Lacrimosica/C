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
CMAKE_SOURCE_DIR = /home/lucky/CLionProjects/Session_18

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lucky/CLionProjects/Session_18/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Session_18.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Session_18.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Session_18.dir/flags.make

CMakeFiles/Session_18.dir/main.c.o: CMakeFiles/Session_18.dir/flags.make
CMakeFiles/Session_18.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucky/CLionProjects/Session_18/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Session_18.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Session_18.dir/main.c.o   -c /home/lucky/CLionProjects/Session_18/main.c

CMakeFiles/Session_18.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Session_18.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lucky/CLionProjects/Session_18/main.c > CMakeFiles/Session_18.dir/main.c.i

CMakeFiles/Session_18.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Session_18.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lucky/CLionProjects/Session_18/main.c -o CMakeFiles/Session_18.dir/main.c.s

# Object files for target Session_18
Session_18_OBJECTS = \
"CMakeFiles/Session_18.dir/main.c.o"

# External object files for target Session_18
Session_18_EXTERNAL_OBJECTS =

Session_18: CMakeFiles/Session_18.dir/main.c.o
Session_18: CMakeFiles/Session_18.dir/build.make
Session_18: CMakeFiles/Session_18.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lucky/CLionProjects/Session_18/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Session_18"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Session_18.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Session_18.dir/build: Session_18

.PHONY : CMakeFiles/Session_18.dir/build

CMakeFiles/Session_18.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Session_18.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Session_18.dir/clean

CMakeFiles/Session_18.dir/depend:
	cd /home/lucky/CLionProjects/Session_18/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lucky/CLionProjects/Session_18 /home/lucky/CLionProjects/Session_18 /home/lucky/CLionProjects/Session_18/cmake-build-debug /home/lucky/CLionProjects/Session_18/cmake-build-debug /home/lucky/CLionProjects/Session_18/cmake-build-debug/CMakeFiles/Session_18.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Session_18.dir/depend


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
CMAKE_SOURCE_DIR = /home/lucky/CLionProjects/Session_19

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lucky/CLionProjects/Session_19/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Session_19.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Session_19.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Session_19.dir/flags.make

CMakeFiles/Session_19.dir/main.c.o: CMakeFiles/Session_19.dir/flags.make
CMakeFiles/Session_19.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucky/CLionProjects/Session_19/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Session_19.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Session_19.dir/main.c.o   -c /home/lucky/CLionProjects/Session_19/main.c

CMakeFiles/Session_19.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Session_19.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lucky/CLionProjects/Session_19/main.c > CMakeFiles/Session_19.dir/main.c.i

CMakeFiles/Session_19.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Session_19.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lucky/CLionProjects/Session_19/main.c -o CMakeFiles/Session_19.dir/main.c.s

# Object files for target Session_19
Session_19_OBJECTS = \
"CMakeFiles/Session_19.dir/main.c.o"

# External object files for target Session_19
Session_19_EXTERNAL_OBJECTS =

Session_19: CMakeFiles/Session_19.dir/main.c.o
Session_19: CMakeFiles/Session_19.dir/build.make
Session_19: CMakeFiles/Session_19.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lucky/CLionProjects/Session_19/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Session_19"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Session_19.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Session_19.dir/build: Session_19

.PHONY : CMakeFiles/Session_19.dir/build

CMakeFiles/Session_19.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Session_19.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Session_19.dir/clean

CMakeFiles/Session_19.dir/depend:
	cd /home/lucky/CLionProjects/Session_19/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lucky/CLionProjects/Session_19 /home/lucky/CLionProjects/Session_19 /home/lucky/CLionProjects/Session_19/cmake-build-debug /home/lucky/CLionProjects/Session_19/cmake-build-debug /home/lucky/CLionProjects/Session_19/cmake-build-debug/CMakeFiles/Session_19.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Session_19.dir/depend


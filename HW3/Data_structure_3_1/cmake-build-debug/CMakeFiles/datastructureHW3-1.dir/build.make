# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kangkang/CLionProjects/datastructureHW3-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kangkang/CLionProjects/datastructureHW3-1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/datastructureHW3-1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/datastructureHW3-1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/datastructureHW3-1.dir/flags.make

CMakeFiles/datastructureHW3-1.dir/main.c.o: CMakeFiles/datastructureHW3-1.dir/flags.make
CMakeFiles/datastructureHW3-1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kangkang/CLionProjects/datastructureHW3-1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/datastructureHW3-1.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/datastructureHW3-1.dir/main.c.o -c /Users/kangkang/CLionProjects/datastructureHW3-1/main.c

CMakeFiles/datastructureHW3-1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/datastructureHW3-1.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kangkang/CLionProjects/datastructureHW3-1/main.c > CMakeFiles/datastructureHW3-1.dir/main.c.i

CMakeFiles/datastructureHW3-1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/datastructureHW3-1.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kangkang/CLionProjects/datastructureHW3-1/main.c -o CMakeFiles/datastructureHW3-1.dir/main.c.s

# Object files for target datastructureHW3-1
datastructureHW3__1_OBJECTS = \
"CMakeFiles/datastructureHW3-1.dir/main.c.o"

# External object files for target datastructureHW3-1
datastructureHW3__1_EXTERNAL_OBJECTS =

datastructureHW3-1: CMakeFiles/datastructureHW3-1.dir/main.c.o
datastructureHW3-1: CMakeFiles/datastructureHW3-1.dir/build.make
datastructureHW3-1: CMakeFiles/datastructureHW3-1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kangkang/CLionProjects/datastructureHW3-1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable datastructureHW3-1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/datastructureHW3-1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/datastructureHW3-1.dir/build: datastructureHW3-1
.PHONY : CMakeFiles/datastructureHW3-1.dir/build

CMakeFiles/datastructureHW3-1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/datastructureHW3-1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/datastructureHW3-1.dir/clean

CMakeFiles/datastructureHW3-1.dir/depend:
	cd /Users/kangkang/CLionProjects/datastructureHW3-1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kangkang/CLionProjects/datastructureHW3-1 /Users/kangkang/CLionProjects/datastructureHW3-1 /Users/kangkang/CLionProjects/datastructureHW3-1/cmake-build-debug /Users/kangkang/CLionProjects/datastructureHW3-1/cmake-build-debug /Users/kangkang/CLionProjects/datastructureHW3-1/cmake-build-debug/CMakeFiles/datastructureHW3-1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/datastructureHW3-1.dir/depend


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
CMAKE_SOURCE_DIR = /Users/kangkang/CLionProjects/dataStructure4_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kangkang/CLionProjects/dataStructure4_1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dataStructure4_1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/dataStructure4_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dataStructure4_1.dir/flags.make

CMakeFiles/dataStructure4_1.dir/main.c.o: CMakeFiles/dataStructure4_1.dir/flags.make
CMakeFiles/dataStructure4_1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kangkang/CLionProjects/dataStructure4_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/dataStructure4_1.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dataStructure4_1.dir/main.c.o -c /Users/kangkang/CLionProjects/dataStructure4_1/main.c

CMakeFiles/dataStructure4_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dataStructure4_1.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kangkang/CLionProjects/dataStructure4_1/main.c > CMakeFiles/dataStructure4_1.dir/main.c.i

CMakeFiles/dataStructure4_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dataStructure4_1.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kangkang/CLionProjects/dataStructure4_1/main.c -o CMakeFiles/dataStructure4_1.dir/main.c.s

# Object files for target dataStructure4_1
dataStructure4_1_OBJECTS = \
"CMakeFiles/dataStructure4_1.dir/main.c.o"

# External object files for target dataStructure4_1
dataStructure4_1_EXTERNAL_OBJECTS =

dataStructure4_1: CMakeFiles/dataStructure4_1.dir/main.c.o
dataStructure4_1: CMakeFiles/dataStructure4_1.dir/build.make
dataStructure4_1: CMakeFiles/dataStructure4_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kangkang/CLionProjects/dataStructure4_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable dataStructure4_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dataStructure4_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dataStructure4_1.dir/build: dataStructure4_1
.PHONY : CMakeFiles/dataStructure4_1.dir/build

CMakeFiles/dataStructure4_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dataStructure4_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dataStructure4_1.dir/clean

CMakeFiles/dataStructure4_1.dir/depend:
	cd /Users/kangkang/CLionProjects/dataStructure4_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kangkang/CLionProjects/dataStructure4_1 /Users/kangkang/CLionProjects/dataStructure4_1 /Users/kangkang/CLionProjects/dataStructure4_1/cmake-build-debug /Users/kangkang/CLionProjects/dataStructure4_1/cmake-build-debug /Users/kangkang/CLionProjects/dataStructure4_1/cmake-build-debug/CMakeFiles/dataStructure4_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dataStructure4_1.dir/depend


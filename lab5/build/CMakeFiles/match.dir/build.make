# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /home/lucas/software/cmake-3.23.0-rc2-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/lucas/software/cmake-3.23.0-rc2-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lucas/PLFB/assign/lab5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lucas/PLFB/assign/lab5/build

# Include any dependencies generated for this target.
include CMakeFiles/match.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/match.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/match.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/match.dir/flags.make

CMakeFiles/match.dir/main.c.o: CMakeFiles/match.dir/flags.make
CMakeFiles/match.dir/main.c.o: ../main.c
CMakeFiles/match.dir/main.c.o: CMakeFiles/match.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/PLFB/assign/lab5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/match.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/match.dir/main.c.o -MF CMakeFiles/match.dir/main.c.o.d -o CMakeFiles/match.dir/main.c.o -c /home/lucas/PLFB/assign/lab5/main.c

CMakeFiles/match.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/match.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lucas/PLFB/assign/lab5/main.c > CMakeFiles/match.dir/main.c.i

CMakeFiles/match.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/match.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lucas/PLFB/assign/lab5/main.c -o CMakeFiles/match.dir/main.c.s

# Object files for target match
match_OBJECTS = \
"CMakeFiles/match.dir/main.c.o"

# External object files for target match
match_EXTERNAL_OBJECTS =

match: CMakeFiles/match.dir/main.c.o
match: CMakeFiles/match.dir/build.make
match: CMakeFiles/match.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lucas/PLFB/assign/lab5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable match"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/match.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/match.dir/build: match
.PHONY : CMakeFiles/match.dir/build

CMakeFiles/match.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/match.dir/cmake_clean.cmake
.PHONY : CMakeFiles/match.dir/clean

CMakeFiles/match.dir/depend:
	cd /home/lucas/PLFB/assign/lab5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lucas/PLFB/assign/lab5 /home/lucas/PLFB/assign/lab5 /home/lucas/PLFB/assign/lab5/build /home/lucas/PLFB/assign/lab5/build /home/lucas/PLFB/assign/lab5/build/CMakeFiles/match.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/match.dir/depend

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
CMAKE_COMMAND = /cygdrive/c/Users/David/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/David/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/David/CLionProjects/Algoritmos-UDC/P2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/David/CLionProjects/Algoritmos-UDC/P2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/P2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/P2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P2.dir/flags.make

CMakeFiles/P2.dir/main.c.o: CMakeFiles/P2.dir/flags.make
CMakeFiles/P2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/David/CLionProjects/Algoritmos-UDC/P2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/P2.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/P2.dir/main.c.o   -c /cygdrive/c/Users/David/CLionProjects/Algoritmos-UDC/P2/main.c

CMakeFiles/P2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/P2.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/David/CLionProjects/Algoritmos-UDC/P2/main.c > CMakeFiles/P2.dir/main.c.i

CMakeFiles/P2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/P2.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/David/CLionProjects/Algoritmos-UDC/P2/main.c -o CMakeFiles/P2.dir/main.c.s

# Object files for target P2
P2_OBJECTS = \
"CMakeFiles/P2.dir/main.c.o"

# External object files for target P2
P2_EXTERNAL_OBJECTS =

P2.exe: CMakeFiles/P2.dir/main.c.o
P2.exe: CMakeFiles/P2.dir/build.make
P2.exe: CMakeFiles/P2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/David/CLionProjects/Algoritmos-UDC/P2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable P2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/P2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P2.dir/build: P2.exe

.PHONY : CMakeFiles/P2.dir/build

CMakeFiles/P2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/P2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/P2.dir/clean

CMakeFiles/P2.dir/depend:
	cd /cygdrive/c/Users/David/CLionProjects/Algoritmos-UDC/P2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/David/CLionProjects/Algoritmos-UDC/P2 /cygdrive/c/Users/David/CLionProjects/Algoritmos-UDC/P2 /cygdrive/c/Users/David/CLionProjects/Algoritmos-UDC/P2/cmake-build-debug /cygdrive/c/Users/David/CLionProjects/Algoritmos-UDC/P2/cmake-build-debug /cygdrive/c/Users/David/CLionProjects/Algoritmos-UDC/P2/cmake-build-debug/CMakeFiles/P2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P2.dir/depend


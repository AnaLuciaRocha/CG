# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ana/Documents/CG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ana/Documents/CG/build

# Include any dependencies generated for this target.
include external/glfw-3.3.3/tests/CMakeFiles/windows.dir/depend.make

# Include the progress variables for this target.
include external/glfw-3.3.3/tests/CMakeFiles/windows.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw-3.3.3/tests/CMakeFiles/windows.dir/flags.make

external/glfw-3.3.3/tests/CMakeFiles/windows.dir/windows.c.o: external/glfw-3.3.3/tests/CMakeFiles/windows.dir/flags.make
external/glfw-3.3.3/tests/CMakeFiles/windows.dir/windows.c.o: ../external/glfw-3.3.3/tests/windows.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ana/Documents/CG/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.3.3/tests/CMakeFiles/windows.dir/windows.c.o"
	cd /home/ana/Documents/CG/build/external/glfw-3.3.3/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/windows.dir/windows.c.o -c /home/ana/Documents/CG/external/glfw-3.3.3/tests/windows.c

external/glfw-3.3.3/tests/CMakeFiles/windows.dir/windows.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/windows.c.i"
	cd /home/ana/Documents/CG/build/external/glfw-3.3.3/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ana/Documents/CG/external/glfw-3.3.3/tests/windows.c > CMakeFiles/windows.dir/windows.c.i

external/glfw-3.3.3/tests/CMakeFiles/windows.dir/windows.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/windows.c.s"
	cd /home/ana/Documents/CG/build/external/glfw-3.3.3/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ana/Documents/CG/external/glfw-3.3.3/tests/windows.c -o CMakeFiles/windows.dir/windows.c.s

external/glfw-3.3.3/tests/CMakeFiles/windows.dir/__/deps/getopt.c.o: external/glfw-3.3.3/tests/CMakeFiles/windows.dir/flags.make
external/glfw-3.3.3/tests/CMakeFiles/windows.dir/__/deps/getopt.c.o: ../external/glfw-3.3.3/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ana/Documents/CG/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object external/glfw-3.3.3/tests/CMakeFiles/windows.dir/__/deps/getopt.c.o"
	cd /home/ana/Documents/CG/build/external/glfw-3.3.3/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/windows.dir/__/deps/getopt.c.o -c /home/ana/Documents/CG/external/glfw-3.3.3/deps/getopt.c

external/glfw-3.3.3/tests/CMakeFiles/windows.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/__/deps/getopt.c.i"
	cd /home/ana/Documents/CG/build/external/glfw-3.3.3/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ana/Documents/CG/external/glfw-3.3.3/deps/getopt.c > CMakeFiles/windows.dir/__/deps/getopt.c.i

external/glfw-3.3.3/tests/CMakeFiles/windows.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/__/deps/getopt.c.s"
	cd /home/ana/Documents/CG/build/external/glfw-3.3.3/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ana/Documents/CG/external/glfw-3.3.3/deps/getopt.c -o CMakeFiles/windows.dir/__/deps/getopt.c.s

external/glfw-3.3.3/tests/CMakeFiles/windows.dir/__/deps/glad_gl.c.o: external/glfw-3.3.3/tests/CMakeFiles/windows.dir/flags.make
external/glfw-3.3.3/tests/CMakeFiles/windows.dir/__/deps/glad_gl.c.o: ../external/glfw-3.3.3/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ana/Documents/CG/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object external/glfw-3.3.3/tests/CMakeFiles/windows.dir/__/deps/glad_gl.c.o"
	cd /home/ana/Documents/CG/build/external/glfw-3.3.3/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/windows.dir/__/deps/glad_gl.c.o -c /home/ana/Documents/CG/external/glfw-3.3.3/deps/glad_gl.c

external/glfw-3.3.3/tests/CMakeFiles/windows.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/__/deps/glad_gl.c.i"
	cd /home/ana/Documents/CG/build/external/glfw-3.3.3/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ana/Documents/CG/external/glfw-3.3.3/deps/glad_gl.c > CMakeFiles/windows.dir/__/deps/glad_gl.c.i

external/glfw-3.3.3/tests/CMakeFiles/windows.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/__/deps/glad_gl.c.s"
	cd /home/ana/Documents/CG/build/external/glfw-3.3.3/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ana/Documents/CG/external/glfw-3.3.3/deps/glad_gl.c -o CMakeFiles/windows.dir/__/deps/glad_gl.c.s

# Object files for target windows
windows_OBJECTS = \
"CMakeFiles/windows.dir/windows.c.o" \
"CMakeFiles/windows.dir/__/deps/getopt.c.o" \
"CMakeFiles/windows.dir/__/deps/glad_gl.c.o"

# External object files for target windows
windows_EXTERNAL_OBJECTS =

external/glfw-3.3.3/tests/windows: external/glfw-3.3.3/tests/CMakeFiles/windows.dir/windows.c.o
external/glfw-3.3.3/tests/windows: external/glfw-3.3.3/tests/CMakeFiles/windows.dir/__/deps/getopt.c.o
external/glfw-3.3.3/tests/windows: external/glfw-3.3.3/tests/CMakeFiles/windows.dir/__/deps/glad_gl.c.o
external/glfw-3.3.3/tests/windows: external/glfw-3.3.3/tests/CMakeFiles/windows.dir/build.make
external/glfw-3.3.3/tests/windows: external/glfw-3.3.3/src/libglfw3.a
external/glfw-3.3.3/tests/windows: /usr/lib/x86_64-linux-gnu/libm.so
external/glfw-3.3.3/tests/windows: /usr/lib/x86_64-linux-gnu/librt.so
external/glfw-3.3.3/tests/windows: /usr/lib/x86_64-linux-gnu/libm.so
external/glfw-3.3.3/tests/windows: /usr/lib/x86_64-linux-gnu/libX11.so
external/glfw-3.3.3/tests/windows: external/glfw-3.3.3/tests/CMakeFiles/windows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ana/Documents/CG/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable windows"
	cd /home/ana/Documents/CG/build/external/glfw-3.3.3/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/windows.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw-3.3.3/tests/CMakeFiles/windows.dir/build: external/glfw-3.3.3/tests/windows

.PHONY : external/glfw-3.3.3/tests/CMakeFiles/windows.dir/build

external/glfw-3.3.3/tests/CMakeFiles/windows.dir/clean:
	cd /home/ana/Documents/CG/build/external/glfw-3.3.3/tests && $(CMAKE_COMMAND) -P CMakeFiles/windows.dir/cmake_clean.cmake
.PHONY : external/glfw-3.3.3/tests/CMakeFiles/windows.dir/clean

external/glfw-3.3.3/tests/CMakeFiles/windows.dir/depend:
	cd /home/ana/Documents/CG/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ana/Documents/CG /home/ana/Documents/CG/external/glfw-3.3.3/tests /home/ana/Documents/CG/build /home/ana/Documents/CG/build/external/glfw-3.3.3/tests /home/ana/Documents/CG/build/external/glfw-3.3.3/tests/CMakeFiles/windows.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw-3.3.3/tests/CMakeFiles/windows.dir/depend


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
CMAKE_BINARY_DIR = /home/ana/Documents/CG/tp1

# Include any dependencies generated for this target.
include external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/depend.make

# Include the progress variables for this target.
include external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/flags.make

external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/sharing.c.o: external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/flags.make
external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/sharing.c.o: ../external/glfw-3.3.3/examples/sharing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ana/Documents/CG/tp1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/sharing.c.o"
	cd /home/ana/Documents/CG/tp1/external/glfw-3.3.3/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sharing.dir/sharing.c.o -c /home/ana/Documents/CG/external/glfw-3.3.3/examples/sharing.c

external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/sharing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sharing.dir/sharing.c.i"
	cd /home/ana/Documents/CG/tp1/external/glfw-3.3.3/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ana/Documents/CG/external/glfw-3.3.3/examples/sharing.c > CMakeFiles/sharing.dir/sharing.c.i

external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/sharing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sharing.dir/sharing.c.s"
	cd /home/ana/Documents/CG/tp1/external/glfw-3.3.3/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ana/Documents/CG/external/glfw-3.3.3/examples/sharing.c -o CMakeFiles/sharing.dir/sharing.c.s

external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/__/deps/glad_gl.c.o: external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/flags.make
external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/__/deps/glad_gl.c.o: ../external/glfw-3.3.3/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ana/Documents/CG/tp1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/__/deps/glad_gl.c.o"
	cd /home/ana/Documents/CG/tp1/external/glfw-3.3.3/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sharing.dir/__/deps/glad_gl.c.o -c /home/ana/Documents/CG/external/glfw-3.3.3/deps/glad_gl.c

external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sharing.dir/__/deps/glad_gl.c.i"
	cd /home/ana/Documents/CG/tp1/external/glfw-3.3.3/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ana/Documents/CG/external/glfw-3.3.3/deps/glad_gl.c > CMakeFiles/sharing.dir/__/deps/glad_gl.c.i

external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sharing.dir/__/deps/glad_gl.c.s"
	cd /home/ana/Documents/CG/tp1/external/glfw-3.3.3/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ana/Documents/CG/external/glfw-3.3.3/deps/glad_gl.c -o CMakeFiles/sharing.dir/__/deps/glad_gl.c.s

# Object files for target sharing
sharing_OBJECTS = \
"CMakeFiles/sharing.dir/sharing.c.o" \
"CMakeFiles/sharing.dir/__/deps/glad_gl.c.o"

# External object files for target sharing
sharing_EXTERNAL_OBJECTS =

external/glfw-3.3.3/examples/sharing: external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/sharing.c.o
external/glfw-3.3.3/examples/sharing: external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/__/deps/glad_gl.c.o
external/glfw-3.3.3/examples/sharing: external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/build.make
external/glfw-3.3.3/examples/sharing: external/glfw-3.3.3/src/libglfw3.a
external/glfw-3.3.3/examples/sharing: /usr/lib/x86_64-linux-gnu/libm.so
external/glfw-3.3.3/examples/sharing: /usr/lib/x86_64-linux-gnu/librt.so
external/glfw-3.3.3/examples/sharing: /usr/lib/x86_64-linux-gnu/libm.so
external/glfw-3.3.3/examples/sharing: /usr/lib/x86_64-linux-gnu/libX11.so
external/glfw-3.3.3/examples/sharing: external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ana/Documents/CG/tp1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable sharing"
	cd /home/ana/Documents/CG/tp1/external/glfw-3.3.3/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sharing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/build: external/glfw-3.3.3/examples/sharing

.PHONY : external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/build

external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/clean:
	cd /home/ana/Documents/CG/tp1/external/glfw-3.3.3/examples && $(CMAKE_COMMAND) -P CMakeFiles/sharing.dir/cmake_clean.cmake
.PHONY : external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/clean

external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/depend:
	cd /home/ana/Documents/CG/tp1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ana/Documents/CG /home/ana/Documents/CG/external/glfw-3.3.3/examples /home/ana/Documents/CG/tp1 /home/ana/Documents/CG/tp1/external/glfw-3.3.3/examples /home/ana/Documents/CG/tp1/external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw-3.3.3/examples/CMakeFiles/sharing.dir/depend


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
CMAKE_COMMAND = /snap/clion/152/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/152/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pavel/CLionProjects/lab12_alg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pavel/CLionProjects/lab12_alg/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab12_alg.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab12_alg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab12_alg.dir/flags.make

CMakeFiles/lab12_alg.dir/main.cpp.o: CMakeFiles/lab12_alg.dir/flags.make
CMakeFiles/lab12_alg.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pavel/CLionProjects/lab12_alg/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab12_alg.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab12_alg.dir/main.cpp.o -c /home/pavel/CLionProjects/lab12_alg/main.cpp

CMakeFiles/lab12_alg.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab12_alg.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pavel/CLionProjects/lab12_alg/main.cpp > CMakeFiles/lab12_alg.dir/main.cpp.i

CMakeFiles/lab12_alg.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab12_alg.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pavel/CLionProjects/lab12_alg/main.cpp -o CMakeFiles/lab12_alg.dir/main.cpp.s

# Object files for target lab12_alg
lab12_alg_OBJECTS = \
"CMakeFiles/lab12_alg.dir/main.cpp.o"

# External object files for target lab12_alg
lab12_alg_EXTERNAL_OBJECTS =

lab12_alg: CMakeFiles/lab12_alg.dir/main.cpp.o
lab12_alg: CMakeFiles/lab12_alg.dir/build.make
lab12_alg: CMakeFiles/lab12_alg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pavel/CLionProjects/lab12_alg/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab12_alg"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab12_alg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab12_alg.dir/build: lab12_alg

.PHONY : CMakeFiles/lab12_alg.dir/build

CMakeFiles/lab12_alg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab12_alg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab12_alg.dir/clean

CMakeFiles/lab12_alg.dir/depend:
	cd /home/pavel/CLionProjects/lab12_alg/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pavel/CLionProjects/lab12_alg /home/pavel/CLionProjects/lab12_alg /home/pavel/CLionProjects/lab12_alg/cmake-build-debug /home/pavel/CLionProjects/lab12_alg/cmake-build-debug /home/pavel/CLionProjects/lab12_alg/cmake-build-debug/CMakeFiles/lab12_alg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab12_alg.dir/depend


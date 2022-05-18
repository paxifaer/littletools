# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/github/wd/littletools

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/github/wd/littletools/build

# Include any dependencies generated for this target.
include queue/CMakeFiles/uoqueue.dir/depend.make

# Include the progress variables for this target.
include queue/CMakeFiles/uoqueue.dir/progress.make

# Include the compile flags for this target's objects.
include queue/CMakeFiles/uoqueue.dir/flags.make

queue/CMakeFiles/uoqueue.dir/rte_ring.cpp.o: queue/CMakeFiles/uoqueue.dir/flags.make
queue/CMakeFiles/uoqueue.dir/rte_ring.cpp.o: ../queue/rte_ring.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/github/wd/littletools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object queue/CMakeFiles/uoqueue.dir/rte_ring.cpp.o"
	cd /home/github/wd/littletools/build/queue && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/uoqueue.dir/rte_ring.cpp.o -c /home/github/wd/littletools/queue/rte_ring.cpp

queue/CMakeFiles/uoqueue.dir/rte_ring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uoqueue.dir/rte_ring.cpp.i"
	cd /home/github/wd/littletools/build/queue && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/github/wd/littletools/queue/rte_ring.cpp > CMakeFiles/uoqueue.dir/rte_ring.cpp.i

queue/CMakeFiles/uoqueue.dir/rte_ring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uoqueue.dir/rte_ring.cpp.s"
	cd /home/github/wd/littletools/build/queue && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/github/wd/littletools/queue/rte_ring.cpp -o CMakeFiles/uoqueue.dir/rte_ring.cpp.s

# Object files for target uoqueue
uoqueue_OBJECTS = \
"CMakeFiles/uoqueue.dir/rte_ring.cpp.o"

# External object files for target uoqueue
uoqueue_EXTERNAL_OBJECTS =

lib/libuoqueue.so: queue/CMakeFiles/uoqueue.dir/rte_ring.cpp.o
lib/libuoqueue.so: queue/CMakeFiles/uoqueue.dir/build.make
lib/libuoqueue.so: queue/CMakeFiles/uoqueue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/github/wd/littletools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../lib/libuoqueue.so"
	cd /home/github/wd/littletools/build/queue && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/uoqueue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
queue/CMakeFiles/uoqueue.dir/build: lib/libuoqueue.so

.PHONY : queue/CMakeFiles/uoqueue.dir/build

queue/CMakeFiles/uoqueue.dir/clean:
	cd /home/github/wd/littletools/build/queue && $(CMAKE_COMMAND) -P CMakeFiles/uoqueue.dir/cmake_clean.cmake
.PHONY : queue/CMakeFiles/uoqueue.dir/clean

queue/CMakeFiles/uoqueue.dir/depend:
	cd /home/github/wd/littletools/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/github/wd/littletools /home/github/wd/littletools/queue /home/github/wd/littletools/build /home/github/wd/littletools/build/queue /home/github/wd/littletools/build/queue/CMakeFiles/uoqueue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : queue/CMakeFiles/uoqueue.dir/depend


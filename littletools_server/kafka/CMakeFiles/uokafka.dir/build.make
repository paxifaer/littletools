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
include kafka/CMakeFiles/uokafka.dir/depend.make

# Include the progress variables for this target.
include kafka/CMakeFiles/uokafka.dir/progress.make

# Include the compile flags for this target's objects.
include kafka/CMakeFiles/uokafka.dir/flags.make

kafka/CMakeFiles/uokafka.dir/simplewrapkafka.cpp.o: kafka/CMakeFiles/uokafka.dir/flags.make
kafka/CMakeFiles/uokafka.dir/simplewrapkafka.cpp.o: ../kafka/simplewrapkafka.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/github/wd/littletools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object kafka/CMakeFiles/uokafka.dir/simplewrapkafka.cpp.o"
	cd /home/github/wd/littletools/build/kafka && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/uokafka.dir/simplewrapkafka.cpp.o -c /home/github/wd/littletools/kafka/simplewrapkafka.cpp

kafka/CMakeFiles/uokafka.dir/simplewrapkafka.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uokafka.dir/simplewrapkafka.cpp.i"
	cd /home/github/wd/littletools/build/kafka && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/github/wd/littletools/kafka/simplewrapkafka.cpp > CMakeFiles/uokafka.dir/simplewrapkafka.cpp.i

kafka/CMakeFiles/uokafka.dir/simplewrapkafka.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uokafka.dir/simplewrapkafka.cpp.s"
	cd /home/github/wd/littletools/build/kafka && /usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/github/wd/littletools/kafka/simplewrapkafka.cpp -o CMakeFiles/uokafka.dir/simplewrapkafka.cpp.s

# Object files for target uokafka
uokafka_OBJECTS = \
"CMakeFiles/uokafka.dir/simplewrapkafka.cpp.o"

# External object files for target uokafka
uokafka_EXTERNAL_OBJECTS =

lib/libuokafka.so: kafka/CMakeFiles/uokafka.dir/simplewrapkafka.cpp.o
lib/libuokafka.so: kafka/CMakeFiles/uokafka.dir/build.make
lib/libuokafka.so: kafka/CMakeFiles/uokafka.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/github/wd/littletools/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../lib/libuokafka.so"
	cd /home/github/wd/littletools/build/kafka && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/uokafka.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
kafka/CMakeFiles/uokafka.dir/build: lib/libuokafka.so

.PHONY : kafka/CMakeFiles/uokafka.dir/build

kafka/CMakeFiles/uokafka.dir/clean:
	cd /home/github/wd/littletools/build/kafka && $(CMAKE_COMMAND) -P CMakeFiles/uokafka.dir/cmake_clean.cmake
.PHONY : kafka/CMakeFiles/uokafka.dir/clean

kafka/CMakeFiles/uokafka.dir/depend:
	cd /home/github/wd/littletools/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/github/wd/littletools /home/github/wd/littletools/kafka /home/github/wd/littletools/build /home/github/wd/littletools/build/kafka /home/github/wd/littletools/build/kafka/CMakeFiles/uokafka.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : kafka/CMakeFiles/uokafka.dir/depend


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
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ujin_ialy/Skillbox-Homework/hw_19.5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ujin_ialy/Skillbox-Homework/hw_19.5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hw_19_5.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/hw_19_5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw_19_5.dir/flags.make

CMakeFiles/hw_19_5.dir/main.cpp.o: CMakeFiles/hw_19_5.dir/flags.make
CMakeFiles/hw_19_5.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ujin_ialy/Skillbox-Homework/hw_19.5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw_19_5.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw_19_5.dir/main.cpp.o -c /home/ujin_ialy/Skillbox-Homework/hw_19.5/main.cpp

CMakeFiles/hw_19_5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw_19_5.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ujin_ialy/Skillbox-Homework/hw_19.5/main.cpp > CMakeFiles/hw_19_5.dir/main.cpp.i

CMakeFiles/hw_19_5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw_19_5.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ujin_ialy/Skillbox-Homework/hw_19.5/main.cpp -o CMakeFiles/hw_19_5.dir/main.cpp.s

# Object files for target hw_19_5
hw_19_5_OBJECTS = \
"CMakeFiles/hw_19_5.dir/main.cpp.o"

# External object files for target hw_19_5
hw_19_5_EXTERNAL_OBJECTS =

hw_19_5: CMakeFiles/hw_19_5.dir/main.cpp.o
hw_19_5: CMakeFiles/hw_19_5.dir/build.make
hw_19_5: CMakeFiles/hw_19_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ujin_ialy/Skillbox-Homework/hw_19.5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hw_19_5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw_19_5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw_19_5.dir/build: hw_19_5
.PHONY : CMakeFiles/hw_19_5.dir/build

CMakeFiles/hw_19_5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw_19_5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw_19_5.dir/clean

CMakeFiles/hw_19_5.dir/depend:
	cd /home/ujin_ialy/Skillbox-Homework/hw_19.5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ujin_ialy/Skillbox-Homework/hw_19.5 /home/ujin_ialy/Skillbox-Homework/hw_19.5 /home/ujin_ialy/Skillbox-Homework/hw_19.5/cmake-build-debug /home/ujin_ialy/Skillbox-Homework/hw_19.5/cmake-build-debug /home/ujin_ialy/Skillbox-Homework/hw_19.5/cmake-build-debug/CMakeFiles/hw_19_5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw_19_5.dir/depend


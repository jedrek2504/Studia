# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /home/student/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/213.6777.58/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/student/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/213.6777.58/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/TestProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TestProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TestProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestProject.dir/flags.make

CMakeFiles/TestProject.dir/test/master.cpp.o: CMakeFiles/TestProject.dir/flags.make
CMakeFiles/TestProject.dir/test/master.cpp.o: ../test/master.cpp
CMakeFiles/TestProject.dir/test/master.cpp.o: CMakeFiles/TestProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestProject.dir/test/master.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestProject.dir/test/master.cpp.o -MF CMakeFiles/TestProject.dir/test/master.cpp.o.d -o CMakeFiles/TestProject.dir/test/master.cpp.o -c "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/test/master.cpp"

CMakeFiles/TestProject.dir/test/master.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestProject.dir/test/master.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/test/master.cpp" > CMakeFiles/TestProject.dir/test/master.cpp.i

CMakeFiles/TestProject.dir/test/master.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestProject.dir/test/master.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/test/master.cpp" -o CMakeFiles/TestProject.dir/test/master.cpp.s

CMakeFiles/TestProject.dir/test/PociagTest.cpp.o: CMakeFiles/TestProject.dir/flags.make
CMakeFiles/TestProject.dir/test/PociagTest.cpp.o: ../test/PociagTest.cpp
CMakeFiles/TestProject.dir/test/PociagTest.cpp.o: CMakeFiles/TestProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TestProject.dir/test/PociagTest.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestProject.dir/test/PociagTest.cpp.o -MF CMakeFiles/TestProject.dir/test/PociagTest.cpp.o.d -o CMakeFiles/TestProject.dir/test/PociagTest.cpp.o -c "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/test/PociagTest.cpp"

CMakeFiles/TestProject.dir/test/PociagTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestProject.dir/test/PociagTest.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/test/PociagTest.cpp" > CMakeFiles/TestProject.dir/test/PociagTest.cpp.i

CMakeFiles/TestProject.dir/test/PociagTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestProject.dir/test/PociagTest.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/test/PociagTest.cpp" -o CMakeFiles/TestProject.dir/test/PociagTest.cpp.s

CMakeFiles/TestProject.dir/test/BasicModelTest.cpp.o: CMakeFiles/TestProject.dir/flags.make
CMakeFiles/TestProject.dir/test/BasicModelTest.cpp.o: ../test/BasicModelTest.cpp
CMakeFiles/TestProject.dir/test/BasicModelTest.cpp.o: CMakeFiles/TestProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TestProject.dir/test/BasicModelTest.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestProject.dir/test/BasicModelTest.cpp.o -MF CMakeFiles/TestProject.dir/test/BasicModelTest.cpp.o.d -o CMakeFiles/TestProject.dir/test/BasicModelTest.cpp.o -c "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/test/BasicModelTest.cpp"

CMakeFiles/TestProject.dir/test/BasicModelTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestProject.dir/test/BasicModelTest.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/test/BasicModelTest.cpp" > CMakeFiles/TestProject.dir/test/BasicModelTest.cpp.i

CMakeFiles/TestProject.dir/test/BasicModelTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestProject.dir/test/BasicModelTest.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/test/BasicModelTest.cpp" -o CMakeFiles/TestProject.dir/test/BasicModelTest.cpp.s

# Object files for target TestProject
TestProject_OBJECTS = \
"CMakeFiles/TestProject.dir/test/master.cpp.o" \
"CMakeFiles/TestProject.dir/test/PociagTest.cpp.o" \
"CMakeFiles/TestProject.dir/test/BasicModelTest.cpp.o"

# External object files for target TestProject
TestProject_EXTERNAL_OBJECTS =

TestProject: CMakeFiles/TestProject.dir/test/master.cpp.o
TestProject: CMakeFiles/TestProject.dir/test/PociagTest.cpp.o
TestProject: CMakeFiles/TestProject.dir/test/BasicModelTest.cpp.o
TestProject: CMakeFiles/TestProject.dir/build.make
TestProject: /usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.so
TestProject: CMakeFiles/TestProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable TestProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestProject.dir/build: TestProject
.PHONY : CMakeFiles/TestProject.dir/build

CMakeFiles/TestProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestProject.dir/clean

CMakeFiles/TestProject.dir/depend:
	cd "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi" "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi" "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/cmake-build-debug" "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/cmake-build-debug" "/home/student/Studia/KOLOSY/starty same/MKAR_2018_Pociag/Pociągi/cmake-build-debug/CMakeFiles/TestProject.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TestProject.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3

# Include any dependencies generated for this target.
include CMakeFiles/a.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/a.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a.out.dir/flags.make

CMakeFiles/a.out.dir/src/Matrix.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/src/Matrix.cpp.o: src/Matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a.out.dir/src/Matrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/src/Matrix.cpp.o -c /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/src/Matrix.cpp

CMakeFiles/a.out.dir/src/Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/src/Matrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/src/Matrix.cpp > CMakeFiles/a.out.dir/src/Matrix.cpp.i

CMakeFiles/a.out.dir/src/Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/src/Matrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/src/Matrix.cpp -o CMakeFiles/a.out.dir/src/Matrix.cpp.s

CMakeFiles/a.out.dir/src/Matrix.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/src/Matrix.cpp.o.requires

CMakeFiles/a.out.dir/src/Matrix.cpp.o.provides: CMakeFiles/a.out.dir/src/Matrix.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/src/Matrix.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/src/Matrix.cpp.o.provides

CMakeFiles/a.out.dir/src/Matrix.cpp.o.provides.build: CMakeFiles/a.out.dir/src/Matrix.cpp.o


CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.o: src/SystemOfLinearEquations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.o -c /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/src/SystemOfLinearEquations.cpp

CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/src/SystemOfLinearEquations.cpp > CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.i

CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/src/SystemOfLinearEquations.cpp -o CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.s

CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.o.requires

CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.o.provides: CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.o.provides

CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.o.provides.build: CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.o


CMakeFiles/a.out.dir/src/Vector.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/src/Vector.cpp.o: src/Vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/a.out.dir/src/Vector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/src/Vector.cpp.o -c /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/src/Vector.cpp

CMakeFiles/a.out.dir/src/Vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/src/Vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/src/Vector.cpp > CMakeFiles/a.out.dir/src/Vector.cpp.i

CMakeFiles/a.out.dir/src/Vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/src/Vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/src/Vector.cpp -o CMakeFiles/a.out.dir/src/Vector.cpp.s

CMakeFiles/a.out.dir/src/Vector.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/src/Vector.cpp.o.requires

CMakeFiles/a.out.dir/src/Vector.cpp.o.provides: CMakeFiles/a.out.dir/src/Vector.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/src/Vector.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/src/Vector.cpp.o.provides

CMakeFiles/a.out.dir/src/Vector.cpp.o.provides.build: CMakeFiles/a.out.dir/src/Vector.cpp.o


CMakeFiles/a.out.dir/src/main.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/a.out.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/src/main.cpp.o -c /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/src/main.cpp

CMakeFiles/a.out.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/src/main.cpp > CMakeFiles/a.out.dir/src/main.cpp.i

CMakeFiles/a.out.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/src/main.cpp -o CMakeFiles/a.out.dir/src/main.cpp.s

CMakeFiles/a.out.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/src/main.cpp.o.requires

CMakeFiles/a.out.dir/src/main.cpp.o.provides: CMakeFiles/a.out.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/src/main.cpp.o.provides

CMakeFiles/a.out.dir/src/main.cpp.o.provides.build: CMakeFiles/a.out.dir/src/main.cpp.o


CMakeFiles/a.out.dir/src/sysLinEq.cpp.o: CMakeFiles/a.out.dir/flags.make
CMakeFiles/a.out.dir/src/sysLinEq.cpp.o: src/sysLinEq.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/a.out.dir/src/sysLinEq.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a.out.dir/src/sysLinEq.cpp.o -c /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/src/sysLinEq.cpp

CMakeFiles/a.out.dir/src/sysLinEq.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a.out.dir/src/sysLinEq.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/src/sysLinEq.cpp > CMakeFiles/a.out.dir/src/sysLinEq.cpp.i

CMakeFiles/a.out.dir/src/sysLinEq.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a.out.dir/src/sysLinEq.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/src/sysLinEq.cpp -o CMakeFiles/a.out.dir/src/sysLinEq.cpp.s

CMakeFiles/a.out.dir/src/sysLinEq.cpp.o.requires:

.PHONY : CMakeFiles/a.out.dir/src/sysLinEq.cpp.o.requires

CMakeFiles/a.out.dir/src/sysLinEq.cpp.o.provides: CMakeFiles/a.out.dir/src/sysLinEq.cpp.o.requires
	$(MAKE) -f CMakeFiles/a.out.dir/build.make CMakeFiles/a.out.dir/src/sysLinEq.cpp.o.provides.build
.PHONY : CMakeFiles/a.out.dir/src/sysLinEq.cpp.o.provides

CMakeFiles/a.out.dir/src/sysLinEq.cpp.o.provides.build: CMakeFiles/a.out.dir/src/sysLinEq.cpp.o


# Object files for target a.out
a_out_OBJECTS = \
"CMakeFiles/a.out.dir/src/Matrix.cpp.o" \
"CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.o" \
"CMakeFiles/a.out.dir/src/Vector.cpp.o" \
"CMakeFiles/a.out.dir/src/main.cpp.o" \
"CMakeFiles/a.out.dir/src/sysLinEq.cpp.o"

# External object files for target a.out
a_out_EXTERNAL_OBJECTS =

a.out: CMakeFiles/a.out.dir/src/Matrix.cpp.o
a.out: CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.o
a.out: CMakeFiles/a.out.dir/src/Vector.cpp.o
a.out: CMakeFiles/a.out.dir/src/main.cpp.o
a.out: CMakeFiles/a.out.dir/src/sysLinEq.cpp.o
a.out: CMakeFiles/a.out.dir/build.make
a.out: CMakeFiles/a.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable a.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a.out.dir/build: a.out

.PHONY : CMakeFiles/a.out.dir/build

CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/src/Matrix.cpp.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/src/SystemOfLinearEquations.cpp.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/src/Vector.cpp.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/src/main.cpp.o.requires
CMakeFiles/a.out.dir/requires: CMakeFiles/a.out.dir/src/sysLinEq.cpp.o.requires

.PHONY : CMakeFiles/a.out.dir/requires

CMakeFiles/a.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a.out.dir/clean

CMakeFiles/a.out.dir/depend:
	cd /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3 /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3 /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3 /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3 /home/konrad/Dokumenty/ZadaniaPO/ZadaniaPO/Zadanie3/CMakeFiles/a.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a.out.dir/depend


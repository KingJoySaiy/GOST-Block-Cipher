# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\KingJoySaiy\workspace\GOST

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\KingJoySaiy\workspace\GOST\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GOST.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GOST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GOST.dir/flags.make

CMakeFiles/GOST.dir/main.cpp.obj: CMakeFiles/GOST.dir/flags.make
CMakeFiles/GOST.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\KingJoySaiy\workspace\GOST\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GOST.dir/main.cpp.obj"
	C:\PROGRA~1\MinGW64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\GOST.dir\main.cpp.obj -c C:\KingJoySaiy\workspace\GOST\main.cpp

CMakeFiles/GOST.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GOST.dir/main.cpp.i"
	C:\PROGRA~1\MinGW64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\KingJoySaiy\workspace\GOST\main.cpp > CMakeFiles\GOST.dir\main.cpp.i

CMakeFiles/GOST.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GOST.dir/main.cpp.s"
	C:\PROGRA~1\MinGW64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\KingJoySaiy\workspace\GOST\main.cpp -o CMakeFiles\GOST.dir\main.cpp.s

CMakeFiles/GOST.dir/test.cpp.obj: CMakeFiles/GOST.dir/flags.make
CMakeFiles/GOST.dir/test.cpp.obj: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\KingJoySaiy\workspace\GOST\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GOST.dir/test.cpp.obj"
	C:\PROGRA~1\MinGW64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\GOST.dir\test.cpp.obj -c C:\KingJoySaiy\workspace\GOST\test.cpp

CMakeFiles/GOST.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GOST.dir/test.cpp.i"
	C:\PROGRA~1\MinGW64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\KingJoySaiy\workspace\GOST\test.cpp > CMakeFiles\GOST.dir\test.cpp.i

CMakeFiles/GOST.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GOST.dir/test.cpp.s"
	C:\PROGRA~1\MinGW64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\KingJoySaiy\workspace\GOST\test.cpp -o CMakeFiles\GOST.dir\test.cpp.s

# Object files for target GOST
GOST_OBJECTS = \
"CMakeFiles/GOST.dir/main.cpp.obj" \
"CMakeFiles/GOST.dir/test.cpp.obj"

# External object files for target GOST
GOST_EXTERNAL_OBJECTS =

GOST.exe: CMakeFiles/GOST.dir/main.cpp.obj
GOST.exe: CMakeFiles/GOST.dir/test.cpp.obj
GOST.exe: CMakeFiles/GOST.dir/build.make
GOST.exe: CMakeFiles/GOST.dir/linklibs.rsp
GOST.exe: CMakeFiles/GOST.dir/objects1.rsp
GOST.exe: CMakeFiles/GOST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\KingJoySaiy\workspace\GOST\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable GOST.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GOST.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GOST.dir/build: GOST.exe

.PHONY : CMakeFiles/GOST.dir/build

CMakeFiles/GOST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GOST.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GOST.dir/clean

CMakeFiles/GOST.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\KingJoySaiy\workspace\GOST C:\KingJoySaiy\workspace\GOST C:\KingJoySaiy\workspace\GOST\cmake-build-debug C:\KingJoySaiy\workspace\GOST\cmake-build-debug C:\KingJoySaiy\workspace\GOST\cmake-build-debug\CMakeFiles\GOST.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GOST.dir/depend

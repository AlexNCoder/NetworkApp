# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/mosquitto-2.0.18

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430

# Include any dependencies generated for this target.
include lib/cpp/CMakeFiles/mosquittopp.dir/depend.make

# Include the progress variables for this target.
include lib/cpp/CMakeFiles/mosquittopp.dir/progress.make

# Include the compile flags for this target's objects.
include lib/cpp/CMakeFiles/mosquittopp.dir/flags.make

lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o: lib/cpp/CMakeFiles/mosquittopp.dir/flags.make
lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o: /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/mosquitto-2.0.18/lib/cpp/mosquittopp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o"
	cd /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430/lib/cpp && /usr/bin/g++-6   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o -c /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/mosquitto-2.0.18/lib/cpp/mosquittopp.cpp

lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mosquittopp.dir/mosquittopp.cpp.i"
	cd /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430/lib/cpp && /usr/bin/g++-6  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/mosquitto-2.0.18/lib/cpp/mosquittopp.cpp > CMakeFiles/mosquittopp.dir/mosquittopp.cpp.i

lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mosquittopp.dir/mosquittopp.cpp.s"
	cd /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430/lib/cpp && /usr/bin/g++-6  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/mosquitto-2.0.18/lib/cpp/mosquittopp.cpp -o CMakeFiles/mosquittopp.dir/mosquittopp.cpp.s

lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.requires:

.PHONY : lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.requires

lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.provides: lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.requires
	$(MAKE) -f lib/cpp/CMakeFiles/mosquittopp.dir/build.make lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.provides.build
.PHONY : lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.provides

lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.provides.build: lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o


# Object files for target mosquittopp
mosquittopp_OBJECTS = \
"CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o"

# External object files for target mosquittopp
mosquittopp_EXTERNAL_OBJECTS =

lib/cpp/libmosquittopp.so.2.0.18: lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o
lib/cpp/libmosquittopp.so.2.0.18: lib/cpp/CMakeFiles/mosquittopp.dir/build.make
lib/cpp/libmosquittopp.so.2.0.18: lib/libmosquitto.so.2.0.18
lib/cpp/libmosquittopp.so.2.0.18: lib/cpp/CMakeFiles/mosquittopp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libmosquittopp.so"
	cd /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430/lib/cpp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mosquittopp.dir/link.txt --verbose=$(VERBOSE)
	cd /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430/lib/cpp && $(CMAKE_COMMAND) -E cmake_symlink_library libmosquittopp.so.2.0.18 libmosquittopp.so.1 libmosquittopp.so

lib/cpp/libmosquittopp.so.1: lib/cpp/libmosquittopp.so.2.0.18
	@$(CMAKE_COMMAND) -E touch_nocreate lib/cpp/libmosquittopp.so.1

lib/cpp/libmosquittopp.so: lib/cpp/libmosquittopp.so.2.0.18
	@$(CMAKE_COMMAND) -E touch_nocreate lib/cpp/libmosquittopp.so

# Rule to build all files generated by this target.
lib/cpp/CMakeFiles/mosquittopp.dir/build: lib/cpp/libmosquittopp.so

.PHONY : lib/cpp/CMakeFiles/mosquittopp.dir/build

lib/cpp/CMakeFiles/mosquittopp.dir/requires: lib/cpp/CMakeFiles/mosquittopp.dir/mosquittopp.cpp.o.requires

.PHONY : lib/cpp/CMakeFiles/mosquittopp.dir/requires

lib/cpp/CMakeFiles/mosquittopp.dir/clean:
	cd /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430/lib/cpp && $(CMAKE_COMMAND) -P CMakeFiles/mosquittopp.dir/cmake_clean.cmake
.PHONY : lib/cpp/CMakeFiles/mosquittopp.dir/clean

lib/cpp/CMakeFiles/mosquittopp.dir/depend:
	cd /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/mosquitto-2.0.18 /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/mosquitto-2.0.18/lib/cpp /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430 /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430/lib/cpp /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430/lib/cpp/CMakeFiles/mosquittopp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/cpp/CMakeFiles/mosquittopp.dir/depend


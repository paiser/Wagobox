# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_SOURCE_DIR = /root/Tango/wago/Wago

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/Tango/wago/Wago

# Include any dependencies generated for this target.
include CMakeFiles/Wago.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Wago.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Wago.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Wago.dir/flags.make

CMakeFiles/Wago.dir/Wago.cpp.o: CMakeFiles/Wago.dir/flags.make
CMakeFiles/Wago.dir/Wago.cpp.o: Wago.cpp
CMakeFiles/Wago.dir/Wago.cpp.o: CMakeFiles/Wago.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Wago.dir/Wago.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wago.dir/Wago.cpp.o -MF CMakeFiles/Wago.dir/Wago.cpp.o.d -o CMakeFiles/Wago.dir/Wago.cpp.o -c /root/Tango/wago/Wago/Wago.cpp

CMakeFiles/Wago.dir/Wago.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wago.dir/Wago.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Tango/wago/Wago/Wago.cpp > CMakeFiles/Wago.dir/Wago.cpp.i

CMakeFiles/Wago.dir/Wago.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wago.dir/Wago.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Tango/wago/Wago/Wago.cpp -o CMakeFiles/Wago.dir/Wago.cpp.s

CMakeFiles/Wago.dir/WagoClass.cpp.o: CMakeFiles/Wago.dir/flags.make
CMakeFiles/Wago.dir/WagoClass.cpp.o: WagoClass.cpp
CMakeFiles/Wago.dir/WagoClass.cpp.o: CMakeFiles/Wago.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Wago.dir/WagoClass.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wago.dir/WagoClass.cpp.o -MF CMakeFiles/Wago.dir/WagoClass.cpp.o.d -o CMakeFiles/Wago.dir/WagoClass.cpp.o -c /root/Tango/wago/Wago/WagoClass.cpp

CMakeFiles/Wago.dir/WagoClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wago.dir/WagoClass.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Tango/wago/Wago/WagoClass.cpp > CMakeFiles/Wago.dir/WagoClass.cpp.i

CMakeFiles/Wago.dir/WagoClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wago.dir/WagoClass.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Tango/wago/Wago/WagoClass.cpp -o CMakeFiles/Wago.dir/WagoClass.cpp.s

CMakeFiles/Wago.dir/WagoStateMachine.cpp.o: CMakeFiles/Wago.dir/flags.make
CMakeFiles/Wago.dir/WagoStateMachine.cpp.o: WagoStateMachine.cpp
CMakeFiles/Wago.dir/WagoStateMachine.cpp.o: CMakeFiles/Wago.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Wago.dir/WagoStateMachine.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wago.dir/WagoStateMachine.cpp.o -MF CMakeFiles/Wago.dir/WagoStateMachine.cpp.o.d -o CMakeFiles/Wago.dir/WagoStateMachine.cpp.o -c /root/Tango/wago/Wago/WagoStateMachine.cpp

CMakeFiles/Wago.dir/WagoStateMachine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wago.dir/WagoStateMachine.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Tango/wago/Wago/WagoStateMachine.cpp > CMakeFiles/Wago.dir/WagoStateMachine.cpp.i

CMakeFiles/Wago.dir/WagoStateMachine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wago.dir/WagoStateMachine.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Tango/wago/Wago/WagoStateMachine.cpp -o CMakeFiles/Wago.dir/WagoStateMachine.cpp.s

CMakeFiles/Wago.dir/ModbusConn.cpp.o: CMakeFiles/Wago.dir/flags.make
CMakeFiles/Wago.dir/ModbusConn.cpp.o: ModbusConn.cpp
CMakeFiles/Wago.dir/ModbusConn.cpp.o: CMakeFiles/Wago.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Wago.dir/ModbusConn.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wago.dir/ModbusConn.cpp.o -MF CMakeFiles/Wago.dir/ModbusConn.cpp.o.d -o CMakeFiles/Wago.dir/ModbusConn.cpp.o -c /root/Tango/wago/Wago/ModbusConn.cpp

CMakeFiles/Wago.dir/ModbusConn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wago.dir/ModbusConn.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Tango/wago/Wago/ModbusConn.cpp > CMakeFiles/Wago.dir/ModbusConn.cpp.i

CMakeFiles/Wago.dir/ModbusConn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wago.dir/ModbusConn.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Tango/wago/Wago/ModbusConn.cpp -o CMakeFiles/Wago.dir/ModbusConn.cpp.s

CMakeFiles/Wago.dir/core_src/BufferHolder.cpp.o: CMakeFiles/Wago.dir/flags.make
CMakeFiles/Wago.dir/core_src/BufferHolder.cpp.o: core_src/BufferHolder.cpp
CMakeFiles/Wago.dir/core_src/BufferHolder.cpp.o: CMakeFiles/Wago.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Wago.dir/core_src/BufferHolder.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wago.dir/core_src/BufferHolder.cpp.o -MF CMakeFiles/Wago.dir/core_src/BufferHolder.cpp.o.d -o CMakeFiles/Wago.dir/core_src/BufferHolder.cpp.o -c /root/Tango/wago/Wago/core_src/BufferHolder.cpp

CMakeFiles/Wago.dir/core_src/BufferHolder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wago.dir/core_src/BufferHolder.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Tango/wago/Wago/core_src/BufferHolder.cpp > CMakeFiles/Wago.dir/core_src/BufferHolder.cpp.i

CMakeFiles/Wago.dir/core_src/BufferHolder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wago.dir/core_src/BufferHolder.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Tango/wago/Wago/core_src/BufferHolder.cpp -o CMakeFiles/Wago.dir/core_src/BufferHolder.cpp.s

CMakeFiles/Wago.dir/core_src/Configurator.cpp.o: CMakeFiles/Wago.dir/flags.make
CMakeFiles/Wago.dir/core_src/Configurator.cpp.o: core_src/Configurator.cpp
CMakeFiles/Wago.dir/core_src/Configurator.cpp.o: CMakeFiles/Wago.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Wago.dir/core_src/Configurator.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wago.dir/core_src/Configurator.cpp.o -MF CMakeFiles/Wago.dir/core_src/Configurator.cpp.o.d -o CMakeFiles/Wago.dir/core_src/Configurator.cpp.o -c /root/Tango/wago/Wago/core_src/Configurator.cpp

CMakeFiles/Wago.dir/core_src/Configurator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wago.dir/core_src/Configurator.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Tango/wago/Wago/core_src/Configurator.cpp > CMakeFiles/Wago.dir/core_src/Configurator.cpp.i

CMakeFiles/Wago.dir/core_src/Configurator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wago.dir/core_src/Configurator.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Tango/wago/Wago/core_src/Configurator.cpp -o CMakeFiles/Wago.dir/core_src/Configurator.cpp.s

CMakeFiles/Wago.dir/core_src/LogicalDevice.cpp.o: CMakeFiles/Wago.dir/flags.make
CMakeFiles/Wago.dir/core_src/LogicalDevice.cpp.o: core_src/LogicalDevice.cpp
CMakeFiles/Wago.dir/core_src/LogicalDevice.cpp.o: CMakeFiles/Wago.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Wago.dir/core_src/LogicalDevice.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wago.dir/core_src/LogicalDevice.cpp.o -MF CMakeFiles/Wago.dir/core_src/LogicalDevice.cpp.o.d -o CMakeFiles/Wago.dir/core_src/LogicalDevice.cpp.o -c /root/Tango/wago/Wago/core_src/LogicalDevice.cpp

CMakeFiles/Wago.dir/core_src/LogicalDevice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wago.dir/core_src/LogicalDevice.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Tango/wago/Wago/core_src/LogicalDevice.cpp > CMakeFiles/Wago.dir/core_src/LogicalDevice.cpp.i

CMakeFiles/Wago.dir/core_src/LogicalDevice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wago.dir/core_src/LogicalDevice.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Tango/wago/Wago/core_src/LogicalDevice.cpp -o CMakeFiles/Wago.dir/core_src/LogicalDevice.cpp.s

CMakeFiles/Wago.dir/core_src/Module.cpp.o: CMakeFiles/Wago.dir/flags.make
CMakeFiles/Wago.dir/core_src/Module.cpp.o: core_src/Module.cpp
CMakeFiles/Wago.dir/core_src/Module.cpp.o: CMakeFiles/Wago.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Wago.dir/core_src/Module.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wago.dir/core_src/Module.cpp.o -MF CMakeFiles/Wago.dir/core_src/Module.cpp.o.d -o CMakeFiles/Wago.dir/core_src/Module.cpp.o -c /root/Tango/wago/Wago/core_src/Module.cpp

CMakeFiles/Wago.dir/core_src/Module.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wago.dir/core_src/Module.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Tango/wago/Wago/core_src/Module.cpp > CMakeFiles/Wago.dir/core_src/Module.cpp.i

CMakeFiles/Wago.dir/core_src/Module.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wago.dir/core_src/Module.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Tango/wago/Wago/core_src/Module.cpp -o CMakeFiles/Wago.dir/core_src/Module.cpp.s

CMakeFiles/Wago.dir/core_src/ModuleDB.cpp.o: CMakeFiles/Wago.dir/flags.make
CMakeFiles/Wago.dir/core_src/ModuleDB.cpp.o: core_src/ModuleDB.cpp
CMakeFiles/Wago.dir/core_src/ModuleDB.cpp.o: CMakeFiles/Wago.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Wago.dir/core_src/ModuleDB.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wago.dir/core_src/ModuleDB.cpp.o -MF CMakeFiles/Wago.dir/core_src/ModuleDB.cpp.o.d -o CMakeFiles/Wago.dir/core_src/ModuleDB.cpp.o -c /root/Tango/wago/Wago/core_src/ModuleDB.cpp

CMakeFiles/Wago.dir/core_src/ModuleDB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wago.dir/core_src/ModuleDB.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Tango/wago/Wago/core_src/ModuleDB.cpp > CMakeFiles/Wago.dir/core_src/ModuleDB.cpp.i

CMakeFiles/Wago.dir/core_src/ModuleDB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wago.dir/core_src/ModuleDB.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Tango/wago/Wago/core_src/ModuleDB.cpp -o CMakeFiles/Wago.dir/core_src/ModuleDB.cpp.s

CMakeFiles/Wago.dir/core_src/PhysValueTransformer.cpp.o: CMakeFiles/Wago.dir/flags.make
CMakeFiles/Wago.dir/core_src/PhysValueTransformer.cpp.o: core_src/PhysValueTransformer.cpp
CMakeFiles/Wago.dir/core_src/PhysValueTransformer.cpp.o: CMakeFiles/Wago.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Wago.dir/core_src/PhysValueTransformer.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wago.dir/core_src/PhysValueTransformer.cpp.o -MF CMakeFiles/Wago.dir/core_src/PhysValueTransformer.cpp.o.d -o CMakeFiles/Wago.dir/core_src/PhysValueTransformer.cpp.o -c /root/Tango/wago/Wago/core_src/PhysValueTransformer.cpp

CMakeFiles/Wago.dir/core_src/PhysValueTransformer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wago.dir/core_src/PhysValueTransformer.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Tango/wago/Wago/core_src/PhysValueTransformer.cpp > CMakeFiles/Wago.dir/core_src/PhysValueTransformer.cpp.i

CMakeFiles/Wago.dir/core_src/PhysValueTransformer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wago.dir/core_src/PhysValueTransformer.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Tango/wago/Wago/core_src/PhysValueTransformer.cpp -o CMakeFiles/Wago.dir/core_src/PhysValueTransformer.cpp.s

CMakeFiles/Wago.dir/core_src/Services.cpp.o: CMakeFiles/Wago.dir/flags.make
CMakeFiles/Wago.dir/core_src/Services.cpp.o: core_src/Services.cpp
CMakeFiles/Wago.dir/core_src/Services.cpp.o: CMakeFiles/Wago.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Wago.dir/core_src/Services.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wago.dir/core_src/Services.cpp.o -MF CMakeFiles/Wago.dir/core_src/Services.cpp.o.d -o CMakeFiles/Wago.dir/core_src/Services.cpp.o -c /root/Tango/wago/Wago/core_src/Services.cpp

CMakeFiles/Wago.dir/core_src/Services.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wago.dir/core_src/Services.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Tango/wago/Wago/core_src/Services.cpp > CMakeFiles/Wago.dir/core_src/Services.cpp.i

CMakeFiles/Wago.dir/core_src/Services.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wago.dir/core_src/Services.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Tango/wago/Wago/core_src/Services.cpp -o CMakeFiles/Wago.dir/core_src/Services.cpp.s

CMakeFiles/Wago.dir/core_src/Tools.cpp.o: CMakeFiles/Wago.dir/flags.make
CMakeFiles/Wago.dir/core_src/Tools.cpp.o: core_src/Tools.cpp
CMakeFiles/Wago.dir/core_src/Tools.cpp.o: CMakeFiles/Wago.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Wago.dir/core_src/Tools.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wago.dir/core_src/Tools.cpp.o -MF CMakeFiles/Wago.dir/core_src/Tools.cpp.o.d -o CMakeFiles/Wago.dir/core_src/Tools.cpp.o -c /root/Tango/wago/Wago/core_src/Tools.cpp

CMakeFiles/Wago.dir/core_src/Tools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wago.dir/core_src/Tools.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Tango/wago/Wago/core_src/Tools.cpp > CMakeFiles/Wago.dir/core_src/Tools.cpp.i

CMakeFiles/Wago.dir/core_src/Tools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wago.dir/core_src/Tools.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Tango/wago/Wago/core_src/Tools.cpp -o CMakeFiles/Wago.dir/core_src/Tools.cpp.s

CMakeFiles/Wago.dir/core_src/WagoDevice.cpp.o: CMakeFiles/Wago.dir/flags.make
CMakeFiles/Wago.dir/core_src/WagoDevice.cpp.o: core_src/WagoDevice.cpp
CMakeFiles/Wago.dir/core_src/WagoDevice.cpp.o: CMakeFiles/Wago.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Wago.dir/core_src/WagoDevice.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wago.dir/core_src/WagoDevice.cpp.o -MF CMakeFiles/Wago.dir/core_src/WagoDevice.cpp.o.d -o CMakeFiles/Wago.dir/core_src/WagoDevice.cpp.o -c /root/Tango/wago/Wago/core_src/WagoDevice.cpp

CMakeFiles/Wago.dir/core_src/WagoDevice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wago.dir/core_src/WagoDevice.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Tango/wago/Wago/core_src/WagoDevice.cpp > CMakeFiles/Wago.dir/core_src/WagoDevice.cpp.i

CMakeFiles/Wago.dir/core_src/WagoDevice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wago.dir/core_src/WagoDevice.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Tango/wago/Wago/core_src/WagoDevice.cpp -o CMakeFiles/Wago.dir/core_src/WagoDevice.cpp.s

CMakeFiles/Wago.dir/ClassFactory.cpp.o: CMakeFiles/Wago.dir/flags.make
CMakeFiles/Wago.dir/ClassFactory.cpp.o: ClassFactory.cpp
CMakeFiles/Wago.dir/ClassFactory.cpp.o: CMakeFiles/Wago.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Wago.dir/ClassFactory.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wago.dir/ClassFactory.cpp.o -MF CMakeFiles/Wago.dir/ClassFactory.cpp.o.d -o CMakeFiles/Wago.dir/ClassFactory.cpp.o -c /root/Tango/wago/Wago/ClassFactory.cpp

CMakeFiles/Wago.dir/ClassFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wago.dir/ClassFactory.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Tango/wago/Wago/ClassFactory.cpp > CMakeFiles/Wago.dir/ClassFactory.cpp.i

CMakeFiles/Wago.dir/ClassFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wago.dir/ClassFactory.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Tango/wago/Wago/ClassFactory.cpp -o CMakeFiles/Wago.dir/ClassFactory.cpp.s

CMakeFiles/Wago.dir/main.cpp.o: CMakeFiles/Wago.dir/flags.make
CMakeFiles/Wago.dir/main.cpp.o: main.cpp
CMakeFiles/Wago.dir/main.cpp.o: CMakeFiles/Wago.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Wago.dir/main.cpp.o"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Wago.dir/main.cpp.o -MF CMakeFiles/Wago.dir/main.cpp.o.d -o CMakeFiles/Wago.dir/main.cpp.o -c /root/Tango/wago/Wago/main.cpp

CMakeFiles/Wago.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Wago.dir/main.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/Tango/wago/Wago/main.cpp > CMakeFiles/Wago.dir/main.cpp.i

CMakeFiles/Wago.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Wago.dir/main.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/Tango/wago/Wago/main.cpp -o CMakeFiles/Wago.dir/main.cpp.s

# Object files for target Wago
Wago_OBJECTS = \
"CMakeFiles/Wago.dir/Wago.cpp.o" \
"CMakeFiles/Wago.dir/WagoClass.cpp.o" \
"CMakeFiles/Wago.dir/WagoStateMachine.cpp.o" \
"CMakeFiles/Wago.dir/ModbusConn.cpp.o" \
"CMakeFiles/Wago.dir/core_src/BufferHolder.cpp.o" \
"CMakeFiles/Wago.dir/core_src/Configurator.cpp.o" \
"CMakeFiles/Wago.dir/core_src/LogicalDevice.cpp.o" \
"CMakeFiles/Wago.dir/core_src/Module.cpp.o" \
"CMakeFiles/Wago.dir/core_src/ModuleDB.cpp.o" \
"CMakeFiles/Wago.dir/core_src/PhysValueTransformer.cpp.o" \
"CMakeFiles/Wago.dir/core_src/Services.cpp.o" \
"CMakeFiles/Wago.dir/core_src/Tools.cpp.o" \
"CMakeFiles/Wago.dir/core_src/WagoDevice.cpp.o" \
"CMakeFiles/Wago.dir/ClassFactory.cpp.o" \
"CMakeFiles/Wago.dir/main.cpp.o"

# External object files for target Wago
Wago_EXTERNAL_OBJECTS =

bin/Wago: CMakeFiles/Wago.dir/Wago.cpp.o
bin/Wago: CMakeFiles/Wago.dir/WagoClass.cpp.o
bin/Wago: CMakeFiles/Wago.dir/WagoStateMachine.cpp.o
bin/Wago: CMakeFiles/Wago.dir/ModbusConn.cpp.o
bin/Wago: CMakeFiles/Wago.dir/core_src/BufferHolder.cpp.o
bin/Wago: CMakeFiles/Wago.dir/core_src/Configurator.cpp.o
bin/Wago: CMakeFiles/Wago.dir/core_src/LogicalDevice.cpp.o
bin/Wago: CMakeFiles/Wago.dir/core_src/Module.cpp.o
bin/Wago: CMakeFiles/Wago.dir/core_src/ModuleDB.cpp.o
bin/Wago: CMakeFiles/Wago.dir/core_src/PhysValueTransformer.cpp.o
bin/Wago: CMakeFiles/Wago.dir/core_src/Services.cpp.o
bin/Wago: CMakeFiles/Wago.dir/core_src/Tools.cpp.o
bin/Wago: CMakeFiles/Wago.dir/core_src/WagoDevice.cpp.o
bin/Wago: CMakeFiles/Wago.dir/ClassFactory.cpp.o
bin/Wago: CMakeFiles/Wago.dir/main.cpp.o
bin/Wago: CMakeFiles/Wago.dir/build.make
bin/Wago: CMakeFiles/Wago.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/Tango/wago/Wago/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable bin/Wago"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Wago.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Wago.dir/build: bin/Wago
.PHONY : CMakeFiles/Wago.dir/build

CMakeFiles/Wago.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Wago.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Wago.dir/clean

CMakeFiles/Wago.dir/depend:
	cd /root/Tango/wago/Wago && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Tango/wago/Wago /root/Tango/wago/Wago /root/Tango/wago/Wago /root/Tango/wago/Wago /root/Tango/wago/Wago/CMakeFiles/Wago.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Wago.dir/depend

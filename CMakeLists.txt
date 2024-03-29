#=============================================================================
#
# file :        CMakeLists.txt
#
# description : File to generate a TANGO device server using cmake.
#
# project :     WagoInterlock
#
#=============================================================================
#                This file is generated by POGO
#        (Program Obviously used to Generate tango Object)
#=============================================================================
#
#
cmake_minimum_required (VERSION 2.8)
set(CMAKE_SKIP_RPATH TRUE)

# MAKE_ENV is the path to find the common environment to build the project
#
if (DEFINED ENV{MAKE_ENV})
    set(MAKE_ENV $ENV{MAKE_ENV})
else()
    set(MAKE_ENV /usr/share/pogo/preferences)
endif()
#
# Project definitions
#
project(WagoInterlock)

#
# optional compiler flags
#
set(CXXFLAGS_USER -g)
# EP
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

#
# Get global information
#
include(${MAKE_ENV}/cmake_tango.opt)

#
# Tango Class list used by project
#

#
# Files for Serial TANGO class
#
set(SERIAL  Serial)
set(SERIAL_PATH  ../SerialLine/src)
set(SERIAL_INCLUDE  ../SerialLine/src)
set(SERIAL_SRC  ${SERIAL_PATH}/${SERIAL}.cpp ${SERIAL_PATH}/${SERIAL}Class.cpp ${SERIAL_PATH}/${SERIAL}StateMachine.cpp)
#
# Files for Modbus TANGO class
#
set(MODBUS  Modbus)
set(MODBUS_PATH  ../Modbus/src)
set(MODBUS_INCLUDE  ../Modbus/src)
set(MODBUS_SRC  ${MODBUS_PATH}/${MODBUS}.cpp ${MODBUS_PATH}/${MODBUS}Class.cpp ${MODBUS_PATH}/${MODBUS}StateMachine.cpp ${MODBUS_PATH}/ModbusCore.cpp ${MODBUS_PATH}/CacheThread.cpp)
#
# Files for Wago TANGO class
#
set(WAGO  Wago)
set(WAGO_PATH  ./Wago)
set(WAGO_INCLUDE  ./Wago)
set(WAGO_SRC  ${WAGO_PATH}/${WAGO}.cpp 
              ${WAGO_PATH}/${WAGO}Class.cpp 
              ${WAGO_PATH}/${WAGO}StateMachine.cpp
              ${WAGO_PATH}/ModbusConn.cpp
              ${WAGO_PATH}/core_src/BufferHolder.cpp
              ${WAGO_PATH}/core_src/Configurator.cpp
              ${WAGO_PATH}/core_src/LogicalDevice.cpp
              ${WAGO_PATH}/core_src/Module.cpp
              ${WAGO_PATH}/core_src/ModuleDB.cpp
              ${WAGO_PATH}/core_src/PhysValueTransformer.cpp
              ${WAGO_PATH}/core_src/Services.cpp
              ${WAGO_PATH}/core_src/Tools.cpp
              ${WAGO_PATH}/core_src/WagoDevice.cpp)
#
# Files for WagoInterlock TANGO class
#
set(WAGOINTERLOCK  WagoInterlock)
set(WAGOINTERLOCK_PATH  ./WagoInterlock)
set(WAGOINTERLOCK_INCLUDE  ./WagoInterlock)
set(WAGOINTERLOCK_SRC  ${WAGOINTERLOCK_PATH}/${WAGOINTERLOCK}.cpp ${WAGOINTERLOCK_PATH}/${WAGOINTERLOCK}Class.cpp ${WAGOINTERLOCK_PATH}/${WAGOINTERLOCK}StateMachine.cpp ${WAGOINTERLOCK_PATH}/Attributes.cpp ${WAGOINTERLOCK_PATH}/InterlockTools.cpp)

#
# User additional include, link folders/libraries and source files
#
set(USER_INCL_DIR /usr/include/tango)
set(USER_LIB_DIR )
set(USER_LIBS )
set(USER_SRC_FILES ${WAGO_PATH}/core_src)

#
# Set global info and include directories
#
set(ALL_CLASS_INCLUDE ${SERIAL_INCLUDE} ${MODBUS_INCLUDE} ${WAGO_INCLUDE} ${WAGOINTERLOCK_INCLUDE} )
set(SERVER_SRC ${SERIAL_SRC} ${MODBUS_SRC} ${WAGO_SRC} ${WAGOINTERLOCK_SRC}  ${USER_SRC_FILES} MultiClassesFactory.cpp main.cpp)
include_directories(${ALL_CLASS_INCLUDE}  ${USER_INCL_DIR} ${TANGO_INCLUDES})

#
# Device Server generation
#
set(SERVER_NAME WagoInterlock)
include(${MAKE_ENV}/cmake_common_target.opt)

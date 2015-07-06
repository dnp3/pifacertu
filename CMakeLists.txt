cmake_minimum_required (VERSION 2.8)
project (pifacertu)
set(PIFACERTU_MAJOR_VERSION 2)
set(PIFACERTU_MINOR_VERSION 0)
set(PIFACERTU_MICRO_VERSION 1)
set(PIFACERTU_VERSION ${PIFACERTU_MAJOR_VERSION}.${PIFACERTU_MINOR_VERSION}.${PIFACERTU_MICRO_VERSION})

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
set(CMAKE_REQUIRED_FLAGS ${CMAKE_CXX_FLAGS})

# different release and debug flags
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

# ----- pifacertu executable -----
add_executable (pifacertu PifaceIOHandler.cpp PifaceRTU.cpp)
target_link_libraries (pifacertu LINK_PUBLIC asiodnp3 opendnp3 asiopal openpal piface-1.0 pthread)

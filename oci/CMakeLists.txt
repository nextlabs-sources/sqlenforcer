# We need CMake 3.8 at least, because we require
# CMAKE_CXX_STANDARD to be set to C++17.
cmake_minimum_required(VERSION 3.10)
# We cannot tolerate most warnings.
set(CMAKE_CXX_FLAGS "-fPIC -Wall -pedantic ${CMAKE_CXX_FLAGS}")
include_directories(./include)
include_directories(./include/oci)
include_directories(../sqlenforcer/include)
include_directories(../commonlib/include)
include_directories(../oci_dae/thirdpart/linux/funchook/include)

add_library(dae_oci SHARED
        ./src/DAEEnforcerMgr.cpp
        ./src/DAEEnforcerWrapper.cpp
        ./src/DAELog.cpp
        ./src/DAEOciExport.cpp
        ./src/DAEOciWrapper.cpp
        ./src/DAETableMetadata.cpp
        ./src/DAEUserAttrsOpr.cpp
        ./src/DAEResourcedata.cpp
        ./src/linux/linuxmain.cpp)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED system log thread filesystem)
target_link_libraries(dae_oci ${Boost_LIBRARIES})

target_link_libraries(dae_oci common)
target_link_libraries(dae_oci dl)
target_link_libraries(dae_oci funchook-static)
#target_link_libraries(dae_oci -static-libgcc -static-libstdc++)

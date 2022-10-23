# We need CMake 3.8 at least, because we require
# CMAKE_CXX_STANDARD to be set to C++17.
cmake_minimum_required(VERSION 3.10)
# We cannot tolerate most warnings.
set(CMAKE_CXX_FLAGS "-fPIC -Wall -pedantic ${CMAKE_CXX_FLAGS}")
include_directories(./third_party)
include_directories(../commonlib/include)
include_directories(../policymgr/include)
include_directories(../userattribute/include)
include_directories(../sqlparser/libsql2003/include)
include_directories(../sqlenforcer/include)
include_directories(../query_cloud_az_sdk/QueryCloudAZSDKCpp/include)

add_executable(unit_test test.cpp)

#target_link_libraries(unit_test odbc_nxl)
target_link_libraries(unit_test common)
#target_link_libraries(unit_test policymgr)
target_link_libraries(unit_test userattribute)
target_link_libraries(unit_test sql2003)
target_link_libraries(unit_test sqlenforcer)

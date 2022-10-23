cmake_minimum_required(VERSION 3.10)
project(linux_odbc_client)
#set(CMAKE_CXX_FLAGS "-lodbc -lpthread ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "-lodbc  ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "-fPIC -Wall -pedantic ${CMAKE_CXX_FLAGS}")

#add_definitions("-Wall -g")
#aux_source_directory(./tool1 SRCS)
aux_source_directory(./tool2 SRCS)
add_executable(ODBCClient ${SRCS})


#include_directories(./microtest)
target_link_libraries(ODBCClient dl)
target_link_libraries(ODBCClient -static-libgcc -static-libstdc++)
#target_link_libraries(ODBCClient odbc_nxl)


aux_source_directory(./tool1 SRCS1)
add_executable(odbc_api_test ${SRCS1})
target_link_libraries(odbc_api_test -static-libgcc -static-libstdc++)
target_link_libraries(odbc_api_test odbc)
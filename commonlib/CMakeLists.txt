# We need CMake 3.8 at least, because we require
# CMAKE_CXX_STANDARD to be set to C++17.
cmake_minimum_required(VERSION 3.10)

project (common)

set(CMAKE_CXX_STANDARD 17)
# We cannot tolerate most warnings.
set(CMAKE_CXX_FLAGS "-fPIC -Wall -pedantic ${CMAKE_CXX_FLAGS}")

aux_source_directory(./src SRCS)

add_library(${PROJECT_NAME} STATIC ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC 
        ./include
        ../sqlparser/libsql2003/include
        ../query_cloud_az_sdk/QueryCloudAZSDKCpp/include
)

set(Boost_USE_STATIC_LIBS ON)
find_package (Boost REQUIRED system log thread filesystem)
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries (${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES})

target_link_libraries(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)

if (UNIX)
    target_link_libraries(${PROJECT_NAME} PRIVATE dl)
endif()
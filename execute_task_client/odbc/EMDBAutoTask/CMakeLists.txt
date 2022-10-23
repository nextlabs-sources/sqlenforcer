cmake_minimum_required(VERSION 3.10)

project(odbc_emdb_auto_task)

set(CMAKE_CXX_STANDARD 14)

############################################################
# Create json library
############################################################
add_library(json STATIC
        third_party/jsoncpp/src/json_reader.cpp
        third_party/jsoncpp/src/json_value.cpp
        third_party/jsoncpp/src/json_valueiterator.inl
        third_party/jsoncpp/src/json_writer.cpp)

target_include_directories(json
        PUBLIC
        third_party/jsoncpp/include)

############################################################
# Create an executable
############################################################

# Remember to reload the CMake project after adding or deleting cpp files
file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE  ${PROJECT_SOURCE_DIR}/include)
if (WIN32)
    target_include_directories(${PROJECT_NAME} PRIVATE  third_party/dirent/include)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE json)
if (UNIX)
    target_link_libraries(${PROJECT_NAME} PRIVATE dl)
endif ()

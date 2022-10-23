# We need CMake 3.8 at least, because we require
# CMAKE_CXX_STANDARD to be set to C++17.
cmake_minimum_required(VERSION 3.10)
project(jdbc)
SET(CMAKE_BUILD_TYPE "Release")
find_package(Java REQUIRED)
if (NOT ${Java_FOUND})
  message(FATAL_ERROR "Java not found (need at least Java8). Please install the JDK or disable that option")
endif()
include(UseJava)

FILE(GLOB_RECURSE SRCS "src/com/nextlabs/EMDB/*.java")

set(JAR_NAME emdb1.3)
set(JAR_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/bin)

add_jar(${JAR_NAME} SOURCES ${SRCS} OUTPUT_DIR ${JAR_OUTPUT_DIR})


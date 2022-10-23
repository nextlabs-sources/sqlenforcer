# We need CMake 3.8 at least, because we require
# CMAKE_CXX_STANDARD to be set to C++17.
cmake_minimum_required(VERSION 3.10)
project(jdbc_mssql)
SET(CMAKE_BUILD_TYPE "Release")
find_package(Java REQUIRED)
if (NOT ${Java_FOUND})
  message(FATAL_ERROR "Java not found (need at least Java8). Please install the JDK or disable that option")
endif()
include(UseJava)

FILE(GLOB_RECURSE SRCS "src/com/nextlabs/jdbc/mssqlproxy/*.java")

set(JAR_NAME mssql-jdbc)
set(JAR_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/bin)
set(JAR_FILE ${JAR_OUTPUT_DIR}/${JAR_NAME}.jar)
set(SERVICES_RELATIVE_PATH "META-INF/services/java.sql.Driver")

add_jar(${JAR_NAME} SOURCES ${SRCS} OUTPUT_DIR ${JAR_OUTPUT_DIR})

add_custom_command(
    TARGET ${JAR_NAME} POST_BUILD
    COMMENT "Add the services info into .jar..."
    DEPENDS ${PROJECT_SOURCE_DIR}/${SERVICES_RELATIVE_PATH}
    COMMAND ${JAVA_ARCHIVE} uvf ${JAR_FILE} -C ${PROJECT_SOURCE_DIR} ${SERVICES_RELATIVE_PATH}
  )

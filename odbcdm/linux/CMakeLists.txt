# We need CMake 3.8 at least, because we require
# CMAKE_CXX_STANDARD to be set to C++17.
cmake_minimum_required(VERSION 3.10)
# We cannot tolerate most warnings.

project(odbc_nxl)

#set(LINK_FLAGS "-Wl,--no-undefined,--version-script,${PROJECT_SOURCE_DIR}/odbc_nxl.map")
set(CMAKE_CXX_FLAGS "-fPIC -Wall -pedantic -fvisibility=hidden -Wl,--version-script=${PROJECT_SOURCE_DIR}/export.map ${CMAKE_CXX_FLAGS}")
#SET_TARGET_PROPERTIES (odbc_nxl PROPERTIES LINK_FLAGS -Wl,--no-undefined,--version-script,${PROJECT_SOURCE_DIR}/export.sym)
#SET_TARGET_PROPERTIES (odbc_nxl PROPERTIES LINK_FLAGS  -Wl,--no-undefined,--version-script,/home/jeff/Workspace/odbcdm/linux/src/export.map)

include_directories(../win32/include)
include_directories(../../commonlib/include)
include_directories(../../sqlenforcer/include)

#aux_source_directory(./win32/src SRCS)

file(GLOB SOURCES "../win32/src/*.cpp")

add_library(odbc_nxl SHARED ${SOURCES})
#target_link_libraries(odbc_nxl dl)
target_link_libraries(${PROJECT_NAME} -static-libgcc -static-libstdc++)
target_link_libraries(${PROJECT_NAME} common)
# Not implicit dependent on "sqlenforcer" will cause crash when call SqlException::SetInfo()
# TODO: Remove implicit dependent on "sqlenforcer"
target_link_libraries(${PROJECT_NAME} sqlenforcer)

if (UNIX)
    if (CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
        add_custom_command(
            TARGET
                ${PROJECT_NAME}
            POST_BUILD
                COMMAND ${CMAKE_OBJCOPY} --only-keep-debug $<TARGET_FILE:${PROJECT_NAME}> $<TARGET_FILE:${PROJECT_NAME}>.debug
                COMMAND ${CMAKE_STRIP} $<TARGET_FILE:${PROJECT_NAME}>
                COMMAND ${CMAKE_OBJCOPY} --add-gnu-debuglink=$<TARGET_FILE:${PROJECT_NAME}>.debug $<TARGET_FILE:${PROJECT_NAME}>
            COMMENT
                "separate symbol file"
            VERBATIM
        )
    endif()
endif()

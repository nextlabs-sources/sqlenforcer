# We need CMake 3.8 at least, because we require
# CMAKE_CXX_STANDARD to be set to C++17.
cmake_minimum_required(VERSION 3.10)

project(userattribute)

# We cannot tolerate most warnings.
set(CMAKE_CXX_FLAGS "-fPIC -Wall -pedantic -Wl,--version-script=${PROJECT_SOURCE_DIR}/export.map ${CMAKE_CXX_FLAGS}")

include_directories(./include)
include_directories(../commonlib/include)

file(GLOB SRC_LIST "./src/log.cpp"
        "./src/operator_between.cpp"
        "./src/userattr.cpp"
        "./src/userattr_export.cpp"
        "./src/userattr_mgr.cpp" )

add_library(${PROJECT_NAME} SHARED ${SRC_LIST})

find_package(Boost 1.65 REQUIRED COMPONENTS thread)

target_link_libraries(${PROJECT_NAME} -static-libgcc -static-libstdc++)
target_link_libraries(${PROJECT_NAME} common Boost::headers Boost::thread)

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
    endif ()
endif()
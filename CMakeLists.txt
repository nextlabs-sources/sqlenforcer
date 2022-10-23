project(sqlenforcer LANGUAGES CXX)

# Find Boost
find_package(Boost 1.67 REQUIRED COMPONENTS thread)

# Find JNI
find_package(JNI REQUIRED)

message(STATUS "JNI_INCLUDE_DIRS: ${JNI_INCLUDE_DIRS}")

aux_source_directory(./src SRCS)
add_library(${PROJECT_NAME} SHARED ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC
    include
    ../sqlparser/libsql2003/include
    ../policymgr/include
    ../userattribute/include
    ../query_cloud_az_sdk/QueryCloudAZSDKCpp/include
    ${JNI_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    common
    dl
    Boost::headers
    Boost::thread
)

if (UNIX)
    target_compile_options(${PROJECT_NAME} PRIVATE -fPIC -fvisibility=hidden -Wall -pedantic)
    target_link_options(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)
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
endif ()

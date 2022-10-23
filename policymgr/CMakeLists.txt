project (daeccpolicymgr)

add_definitions(-DHDB_POLICYMGR_IMP)


aux_source_directory(./src SRCS)
aux_source_directory(./third_party/jsoncpp/src SRCS_JSCPP)

add_library(daeccpolicymgr SHARED
    ${SRCS}
    ${SRCS_JSCPP}
)

target_include_directories(${PROJECT_NAME} PUBLIC
    include
    third_party/dirent/include
    third_party/jsoncpp/include
)

find_package(Boost 1.67 REQUIRED COMPONENTS system date_time thread)
find_package(OpenSSL 1.0 REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Boost::boost
    Boost::system
    Boost::date_time
    Boost::thread
    OpenSSL::SSL
)

if (UNIX)
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
    endif()
endif()

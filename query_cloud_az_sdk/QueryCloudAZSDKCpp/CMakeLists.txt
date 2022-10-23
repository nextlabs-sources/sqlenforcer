project(QueryCloudAZSDKCpp LANGUAGES CXX)

set(SOURCE_FILE_LIST
    src/Attributes.cpp
    src/CommonFun.cpp
    src/Connection.cpp
    src/ConnectionPool.cpp
    src/NXLHttpClient.cpp
    src/Obligation.cpp
    src/PolicyRequest.cpp
    src/PolicyResult.cpp
    src/QueryCloudAZExport.cpp
    src/QueryCloudAZManager.cpp)

# Find Boost
find_package(Boost 1.67 REQUIRED COMPONENTS date_time thread)

# Find OpenSSL
find_package(OpenSSL 1.0 REQUIRED Crypto SSL)

# Create a shared library for explicit linking
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILE_LIST})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Boost::headers
    Boost::date_time
    Boost::thread
    OpenSSL::SSL
    OpenSSL::Crypto
)

if (MSVC)
    target_compile_definitions(${PROJECT_NAME} PUBLIC LEGACY_DEFINITIONS_IOB_FUNC)
elseif (UNIX)
    target_compile_options(${PROJECT_NAME} PRIVATE -fPIC -fvisibility=hidden -Wall -Werror -pedantic)
    target_link_options(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++
        -Wl,--version-script=${PROJECT_SOURCE_DIR}/export.map)
endif ()

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
endif ()

cmake_minimum_required(VERSION 3.10)

project (install_manager)

aux_source_directory(./src SRCS)
aux_source_directory(./src/commands SRCS_COMMANDS)

add_executable (${PROJECT_NAME} ${SRCS} ${SRCS_COMMANDS})

target_include_directories (${PROJECT_NAME} PRIVATE
  ./include
)

target_include_directories (${PROJECT_NAME} PRIVATE 
  ${PROJECT_SOURCE_DIR}/third_party
)

target_link_libraries (${PROJECT_NAME} PRIVATE
  ${PROJECT_SOURCE_DIR}/third_party/NSudo/x64/NSudoAPI.lib
)

find_package (Boost REQUIRED system log thread filesystem program_options)
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries (${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES})

find_package (CLI11 CONFIG REQUIRED)
target_link_libraries (${PROJECT_NAME} PUBLIC common CLI11::CLI11)

find_path(WINREG_INCLUDE_DIRS "winreg/WinReg.hpp")
target_include_directories(${PROJECT_NAME} PRIVATE ${WINREG_INCLUDE_DIRS})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD                 # Adds a post-build event to my project
    COMMAND ${CMAKE_COMMAND} -E copy_if_different                    # which executes "cmake - E copy_if_different..."
        "${PROJECT_SOURCE_DIR}/third_party/NSudo/x64/NSudoAPI.dll"   # <--this is in-file
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)                          # <--this is out-file path
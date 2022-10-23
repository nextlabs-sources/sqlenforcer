cmake_minimum_required (VERSION 3.13)

project (dae_encrypt)

add_executable (${PROJECT_NAME} main.cpp)

target_link_libraries (${PROJECT_NAME} PRIVATE common)


if (UNIX)
  target_link_libraries(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)
endif()

set_target_properties(${PROJECT_NAME}
    PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
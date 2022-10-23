project(test_odbc)

add_executable(${PROJECT_NAME} "")

find_package(Boost 1.67 REQUIRED COMPONENTS system date_time thread)

message(STATUS "Boost_INCLUDE_DIR: ${Boost_INCLUDE_DIR}")

target_include_directories(${PROJECT_NAME} PRIVATE include third_party ${Boost_INCLUDE_DIR})
target_sources(${PROJECT_NAME} PRIVATE
    src/main.cpp
    third_party/nanodbc/nanodbc.cpp
    )
target_link_libraries(${PROJECT_NAME} PRIVATE odbc pthread)


target_link_libraries(${PROJECT_NAME} PUBLIC
    Boost::headers
    Boost::system
    Boost::date_time
    Boost::thread
    )

#find_package(ODBC REQUIRED)
#target_link_libraries(${PROJECT_NAME} PRIVATE ODBC::ODBC)
#
#message(STATUS "ODBC_LIBRARIES: ${ODBC_LIBRARIES}")
#message(STATUS "ODBC_INCLUDE_DIRS: ${ODBC_INCLUDE_DIRS}")

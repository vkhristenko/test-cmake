cmake_minimum_required(VERSION 3.10)

project(prj2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(STATUS "CMAKE_PREFIX_PATH = ${CMAKE_PREFIX_PATH}")

#find_package(package1 CONFIG REQUIRED)
#find_package(package2 CONFIG REQUIRED)

add_subdirectory(${CMAKE_SOURCE_DIR}/prj1 third_party/prj1)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE 
    package1somelib1 package1somelib2 
    package2somelib1 package2somelib2)

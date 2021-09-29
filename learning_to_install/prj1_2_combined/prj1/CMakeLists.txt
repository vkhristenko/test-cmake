cmake_minimum_required(VERSION 3.10)

project(prj1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(prj1_src ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src/package1)
add_subdirectory(src/package2)

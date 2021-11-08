cmake_minimum_required(VERSION 3.15)
project(testlang)

add_executable(testlang main.cpp)
target_link_libraries(testlang)

add_subdirectory(dir1)

include(test_module.cmake)

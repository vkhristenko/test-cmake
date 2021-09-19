cmake_minimum_required(VERSION 3.10)
project(Step3Test VERSION 1.0)

find_package(MathFunctions 1.0 REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(test test.cpp)
target_link_libraries(test PUBLIC MathFunctions1 MathFunctions2)

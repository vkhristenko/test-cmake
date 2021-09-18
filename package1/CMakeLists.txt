cmake_minimum_required(VERSION 3.8)

project (package1 VERSION 0.0.0)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++17")

include_directories(${PROJECT_SOURCE_DIR})

file(GLOB SOURCES *.cpp)
add_library(package1 SHARED ${SOURCES})
target_link_libraries(package1)
install(TARGETS package1)

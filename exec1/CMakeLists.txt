cmake_minimum_required(VERSION 3.10)

# set the project name
project(exec1 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

configure_file(TutorialConfig.h.in TutorialConfig.h)

include_directories(${PROJECT_BINARY_DIR})

if (USE_MYMATH)
    # add the MathFunctions library
    add_subdirectory(util)
    list(APPEND EXTRA_LIBS util)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/util")
endif()

# add the executable
add_executable(main1 main.cpp)
target_link_libraries(main1 PUBLIC ${EXTRA_LIBS})
target_include_directories(main1 PUBLIC ${EXTRA_INCLUDES})

# add the executable
add_executable(main2 main.cpp)
target_link_libraries(main2 PUBLIC ${EXTRA_LIBS})
target_include_directories(main2 PUBLIC ${EXTRA_INCLUDES})

cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

configure_file(TutorialConfig.h.in TutorialConfig.h)

if (USE_MYMATH)
    # add the MathFunctions library
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions1 MathFunctions2)
    #list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# add the executable
add_executable(main1 main.cpp)
target_link_libraries(main1 PUBLIC ${EXTRA_LIBS})
target_include_directories(main1 PUBLIC ${PROJECT_BINARY_DIR})

# add the executable
add_executable(main2 main.cpp)
target_link_libraries(main2 PUBLIC ${EXTRA_LIBS})
target_include_directories(main2 PUBLIC ${PROJECT_BINARY_DIR})

install(TARGETS main1 main2 DESTINATION bin)
install(
    FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
    DESTINATION include
)

#install(EXPORT MathFunctionsTargets
#  FILE MathFunctionsTargets.cmake
#  DESTINATION lib/cmake/MathFunctions
#)

#include(CMakePackageConfigHelpers)
# generate the config file that includes the exports
#configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
#  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake"
#  INSTALL_DESTINATION "lib/cmake/example"
#  NO_SET_AND_CHECK_MACRO
#  NO_CHECK_REQUIRED_COMPONENTS_MACRO
#  )
# generate the version file for the config file
#write_basic_package_version_file(
#  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfigVersion.cmake"
#  VERSION "${Tutorial_VERSION_MAJOR}.${Tutorial_VERSION_MINOR}"
#  COMPATIBILITY AnyNewerVersion
#)

# install the configuration file
#install(FILES
#  ${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake
#  ${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfigVersion.cmake
#  DESTINATION lib/cmake/MathFunctions
#  )

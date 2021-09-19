# to generate at config time
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/MakeTable.sh ${CMAKE_CURRENT_BINARY_DIR}/Table.h
)

add_library(MathFunctions1 SHARED test1.cpp ${CMAKE_CURRENT_BINARY_DIR}/Table.h)
add_library(MathFunctions2 SHARED test2.cpp ${CMAKE_CURRENT_BINARY_DIR}/Table.h)
#target_include_directories(MathFunctions PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
target_include_directories(
    MathFunctions1
    PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include>
)
target_include_directories(
    MathFunctions2
    PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include>
)

install(TARGETS MathFunctions1 DESTINATION lib EXPORT MathFunctionsTargets)
install(TARGETS MathFunctions2 DESTINATION lib EXPORT MathFunctionsTargets)
install(FILES test1.hpp test2.hpp DESTINATION include)

#install(
#  FILE MathFunctionsTargets.cmake
#  DESTINATION lib/cmake/MathFunctions
#)

install(EXPORT MathFunctionsTargets
  FILE MathFunctionsTargets.cmake
  DESTINATION lib/cmake/MathFunctions
)

include(CMakePackageConfigHelpers)
# generate the config file that includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake"
  INSTALL_DESTINATION "lib/cmake/example"
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
  )
# generate the version file for the config file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfigVersion.cmake"
  VERSION "${Tutorial_VERSION_MAJOR}.${Tutorial_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion
)

# install the configuration file
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfigVersion.cmake
  DESTINATION lib/cmake/MathFunctions
  )

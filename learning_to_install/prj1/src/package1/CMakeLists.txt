add_subdirectory(somelib1)
add_subdirectory(somelib2)

#
# to generate a single <package>Config.cmake
#
include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/package1Config.cmake"
    INSTALL_DESTINATION "lib/cmake/package1"
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/package1ConfigVersion.cmake"
    VERSION "0.0"
    COMPATIBILITY AnyNewerVersion
)
install(
    FILES 
        ${CMAKE_CURRENT_BINARY_DIR}/package1Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/package1ConfigVersion.cmake
        DESTINATION lib/cmake/package1
)

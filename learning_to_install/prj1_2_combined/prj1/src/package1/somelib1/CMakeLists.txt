add_library(package1somelib1 source1.cpp source2.cpp)

# BUILD_INTERFACE - expose for the build products
# INSTALL_INTERFACE - export for install products
target_include_directories(
    package1somelib1
    PRIVATE ${prj1_src}/src
    INTERFACE
        $<BUILD_INTERFACE:${prj1_src}/src> 
        $<INSTALL_INTERFACE:include>
)

# for the library target itself
install(
    TARGETS package1somelib1 
    DESTINATION lib
    # forces to generate the config file
    EXPORT package1somelib1Targets
)

# for include files e.g.
install(
    FILES header1.hpp header2.hpp
    DESTINATION include/package1/somelib1
)

# have to explicitly install the config file
install(
    EXPORT package1somelib1Targets
    FILE package1somelib1Targets.cmake
    DESTINATION lib/cmake/package1
    NAMESPACE prj1::
)

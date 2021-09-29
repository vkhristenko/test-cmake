add_library(package2somelib1 source1.cpp source2.cpp)
target_include_directories(
    package2somelib1
    PRIVATE ${CMAKE_SOURCE_DIR}/src
    INTERFACE 
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include>
)

# for the library target itself
install(
    TARGETS package2somelib1 
    DESTINATION lib
    # forces to generate the config file
    EXPORT package2somelib1Targets
)

# for include files e.g.
install(
    FILES header1.hpp header2.hpp
    DESTINATION include/package2/somelib1
)

# have to explicitly install the config file
install(
    EXPORT package2somelib1Targets
    FILE package2somelib1Targets.cmake
    DESTINATION lib/cmake/package2
    NAMESPACE prj1::
)

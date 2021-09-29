add_library(package2somelib2 source1.cpp source2.cpp)
target_include_directories(
    package2somelib2
    PRIVATE ${CMAKE_SOURCE_DIR}/src
    INTERFAE 
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include>
)

install(
    TARGETS package2somelib2
    DESTINATION lib
    EXPORT package2somelib2Targets
)

install(
    FILES header1.hpp header2.hpp
    DESTINATION include/package2/somelib2
)

install(
    EXPORT package2somelib2Targets
    FILE package2somelib2Targets.cmake
    DESTINATION lib/cmake/package2
    NAMESPACE prj1::
)

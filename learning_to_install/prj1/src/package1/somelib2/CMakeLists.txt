add_library(package1somelib2 source1.cpp source2.cpp)

target_include_directories(
    package1somelib2
    PRIVATE ${CMAKE_SOURCE_DIR}/src
    INTERFAE 
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include>
)

install(
    TARGETS package1somelib2
    DESTINATION lib
    EXPORT package1somelib2Targets
)

install(
    FILES header1.hpp header2.hpp
    DESTINATION include/package1/somelib2
)

install(
    EXPORT package1somelib2Targets
    FILE package1somelib2Targets.cmake
    DESTINATION lib/cmake/package1
    NAMESPACE prj1::
)

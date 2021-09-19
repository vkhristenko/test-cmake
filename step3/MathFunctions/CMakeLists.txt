# to generate at config time
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/MakeTable.sh ${CMAKE_CURRENT_BINARY_DIR}/Table.h
)

add_library(MathFunctions SHARED test1.cpp test2.cpp ${CMAKE_CURRENT_BINARY_DIR}/Table.h)
target_include_directories(MathFunctions PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")

#target_include_directories(
#    MathFunctions
#    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
#)

install(TARGETS MathFunctions DESTINATION lib EXPORT MathFunctionsTargets)
install(FILES test1.hpp test2.hpp DESTINATION include)

#install(
#  FILE MathFunctionsTargets.cmake
#  DESTINATION lib/cmake/MathFunctions
#)

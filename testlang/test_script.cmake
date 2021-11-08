message(STATUS "running a test script")

set(SOURCES s1.cpp s2.cpp s3.cpp)
if (DEFINED SOURCES)
    message(STATUS "sources are set")
else()
    message(STATUS "sources are not set")
endif()

set(A 0;1)
set(B 2 3)
set(C 4 5)
set(Q 111;222;333 444 555;666)
set(D 6;7 8)
set(E "")
foreach(X IN LISTS A B C D E Q)
    message(STATUS "X=${X}")
endforeach()

foreach(X "a b c d")
    message(STATUS ${X})
endforeach()

list(APPEND English one two three four)
list(APPEND Bahasa satu dua tiga qqq)

foreach(num IN ZIP_LISTS English Bahasa)
    message(STATUS "num_0=${num_0}, num_1=${num_1}")
endforeach()

foreach(en ba IN ZIP_LISTS English Bahasa)
    message(STATUS "en=${en}, ba=${ba}")
endforeach()

macro(print_3 arg1 arg2 arg3)
    message(STATUS "argc=${ARGC} arg1=${arg1} arg2=${arg2} arg3=${arg3}")
endmacro()

print_3(first second third)

function(fun_print_3 arg1 arg2 arg3)
    message(STATUS "argc=${ARGC} arg1=${arg1} arg2=${arg2} arg3=${arg3}")

    if(DEFINED arg1)
        message(STATUS "arg1 is set")
    endif()
endfunction()

fun_print_3(one two three)

set(SOMEVAR 10)
set(SOMEVARNAME "SOMEVAR")
if(DEFINED ${SOMEVARNAME})
    message(STATUS "some var is defined")
endif()

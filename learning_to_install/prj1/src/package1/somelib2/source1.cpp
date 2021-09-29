#include "package1/somelib2/header1.hpp"

#include <iostream>

namespace package1 {

namespace somelib2 {

void test1() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

}

}

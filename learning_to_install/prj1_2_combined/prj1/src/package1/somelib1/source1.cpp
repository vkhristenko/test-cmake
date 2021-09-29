#include "package1/somelib1/header1.hpp"

#include <iostream>

namespace package1 {

namespace somelib1 {

void test1() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

}

}

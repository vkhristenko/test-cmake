#include "package1/somelib2/header2.hpp"

#include <iostream>

namespace package1 {

namespace somelib2 {

void test2() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

}

}

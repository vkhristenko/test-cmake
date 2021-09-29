#include "package2/somelib1/header2.hpp"

#include <iostream>

namespace package2 {

namespace somelib1 {

void test2() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

}

}

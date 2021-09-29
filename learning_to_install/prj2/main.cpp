#include <iostream>

#include "package1/somelib1/header1.hpp"
#include "package1/somelib1/header2.hpp"
#include "package1/somelib2/header1.hpp"
#include "package1/somelib2/header2.hpp"

#include "package2/somelib1/header1.hpp"
#include "package2/somelib1/header2.hpp"
#include "package2/somelib2/header1.hpp"
#include "package2/somelib2/header2.hpp"

int main() {
    std::cout << "hello world" << std::endl;
    package1::somelib1::test1();
    package1::somelib1::test2();
    package1::somelib2::test1();
    package1::somelib2::test2();
    
    package2::somelib1::test1();
    package2::somelib1::test2();
    package2::somelib2::test1();
    package2::somelib2::test2();

    return 0;
}

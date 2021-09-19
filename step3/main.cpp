#include <iostream>
#include <thread>

#include "TutorialConfig.h"

#ifdef USE_MYMATH
#include "test1.hpp"
#include "test2.hpp"
#endif

int main(int argc, char** argv) {
    auto callme = [=]() {
        std::cout << "hello world from " << argv[0] << std::endl;
        std::cout << "version number = " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;

#ifdef USE_MYMATH
        std::cout << "test1 = " << test1() << "  test2 = " << test2() << std::endl;
#endif
    };
    std::thread t{callme};
    t.join();

    return 0;
}

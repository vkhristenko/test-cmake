#include <iostream>

#include "test1.hpp"

int main(int argc, char** argv) {
    std::cout << argv[0] << std::endl;
    std::cout << "test1 = " << test1() << std::endl;

    return 0;
}

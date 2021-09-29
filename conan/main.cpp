#include <iostream>

#include "Poco/MD5Engine.h"
#include "Poco/DigestStream.h"

int test() {
    Poco::MD5Engine md5;
    Poco::DigestOutputStream ds(md5);
    ds << "abcdefghijklmnopqrstuvwxyz";
    ds.close();
    std::cout << Poco::DigestEngine::digestToHex(md5.digest()) << std::endl;
    return 0;
}

int main() {
    std::cout << "hello world" << std::endl;

    return test();
}

#include <iostream>
#include <string>
#include <vector>

#include "Blob.h"

int main() {
    Blob<std::string> bb;
    bb.push_back("5th");

    bb[0] = "C++";
    std::cout << bb[0] << std::endl;

    return 0;
}
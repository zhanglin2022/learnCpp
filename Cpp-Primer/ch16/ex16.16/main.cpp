#include <iostream>
#include <string>

#include "vec.h"

int main() {
    Vec<std::string> svec{"C++", "Primer"};
    std::cout << svec.capacity() << std::endl;
    svec.push_back("5th");
    for (auto &ele : svec) 
        std::cout << ele << " ";
    std::cout << std::endl;
    std::cout << svec.capacity() << std::endl;

    return 0;
}
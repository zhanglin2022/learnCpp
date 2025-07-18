#include "ex12_2.h"
#include <iostream>

int main() {
    const StrBlob csb{"Sun", "earth" , "Moon"};
    StrBlob sb{"tree", "leaf" , "flower"};

    std::cout << csb.front() << " " << csb.back() << std::endl;
    sb.back() = "bird";
    std::cout << sb.front() << " " << sb.back() << std::endl;

    return 0;
}
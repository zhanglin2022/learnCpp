// Exercise 14.18
// 
// @See Exercise 14.16
//
// Define relational operators for your StrBlob, StrBlobPtr, StrVec, and 
// String classes.
//

#include "ex14_18_StrVec.h"
#include <iostream>

int main() {
    StrVec sv1{"Hello", "World"};
    StrVec sv2{"Cpp", "Primer"};
    std::cout << (sv1 < sv2) << std::endl;

    return 0;
}


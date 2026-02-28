// Exercise 14.26
//
// @See Exercise 14.23
//
// Define subscript operators for your StrVec, String, StrBlob, 
// and StrBlobPtr classes.

#include "ex14_26_StrVec.h"
#include <iostream>

int main() {
    StrVec sv1 = {"Hello", "World!"};
    for (auto idx = 0; idx !=sv1.size(); ++idx) 
        std::cout << sv1[idx] << " ";
    std::cout << std::endl;
    
    return 0;
}

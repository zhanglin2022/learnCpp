// Exercise 14.23
//
// @See Exercise 14.18 StrVec
//
// Define an initializer_list assignment operator for your version of the 
// StrVec class.
//

#include "ex14_23.h"
#include <iostream>

int main() {
    StrVec sv1 = {"Hello", "World!"};
    for (auto i : sv1) 
        std::cout << i << " ";
    std::cout << std::endl;
    
    return 0;
}


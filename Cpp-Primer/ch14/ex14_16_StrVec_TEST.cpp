// Exercise 14.16
//
// @See Exercise 13.49
//
// Define equality and inequality operators for your StrBlob (§ 12.1.1, p. 456), 
// StrBlobPtr (§ 12.1.6, p. 474), StrVec (§ 13.5, p. 526), and String (§ 13.5, p. 531)
// classes.
//

#include "ex14_16_StrVec.h"
#include <iostream>

int main() {
    StrVec sv1{"Hello", "World"};
    StrVec sv2{"Cpp", "Primer"};
    std::cout << (sv1 == sv2) << std::endl;

    return 0;
}

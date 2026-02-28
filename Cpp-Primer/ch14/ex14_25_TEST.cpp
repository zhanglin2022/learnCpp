// Exercise 14.25
//
// @See Exercise 14.15
//
// Implement any other assignment operators your class should define. 
// Explain which types should be used as operands and why.

#include "ex14_25.h"

int main() {
    Book cp5_1(1234, "CP5", "Lippmen", "2012", 5);
    Book cp5_2(1234, "CP5", "Lippmen", "2012", 5);
    std::cout << cp5_1 + cp5_2 << std::endl;
    cp5_2 = 9999;
    std::cout << cp5_2 << std::endl;

    return 0;
}

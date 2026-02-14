// Exercise 14.13
//
// @See ex14_02_TEST.cpp 
// 
// Define the substraction operation for class Sales_data.
//

#include "ex14_13.h"

int main() {
    Sales_data s1("Book1", 100, 10);
    Sales_data s2("Book1", 200, 20);

    std::cout << s1 << std::endl;

    // Addition
    s1 = s1 + s2;
    std::cout << s1 << std::endl;

    // Compound assignment
    s1 += s2;
    std::cout << s1 << std::endl;

    // Substraction
    s1 = s1 - s2;
    std::cout << s1 << std::endl;;

    // Compound assignment
    s1 -= s2;
    std::cout << s1 << std::endl;

    return 0;
}

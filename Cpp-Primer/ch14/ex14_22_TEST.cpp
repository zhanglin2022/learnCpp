// Exercise 14.22
//
// @See Exercise 14.13
//
// Define a version of the assignment operator that can assign a string 
// representing an ISBN to a Sales_data.
//

#include "ex14_22.h"

int main() {
    Sales_data s1("Book1", 100, 10);
    Sales_data s2("Book1", 200, 20);
    auto str = "Book2";

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

    s1 = str;
    std::cout << s1 << std::endl;
    
    return 0;
}

// Exercise 14.45
//
// @See Exercise 14.22
//
// Write conversion operators to convert a Sales_data to string and to double. 
// What values do you think these operators should return?
// 

#include "ex14_45.h"

int main() {
    Sales_data s1("Book1", 5, 120.5);
    std::cout << s1 << std::endl;
    std::cout << static_cast<std::string>(s1) << std::endl;
    std::cout << static_cast<double>(s1) << std::endl;
    
    return 0;
}

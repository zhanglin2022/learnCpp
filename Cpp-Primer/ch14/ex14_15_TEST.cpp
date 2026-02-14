// Exercise 14.15
//
// @See Exercise 14.5
//
// Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define any of 
// the arithmetic operators? 
// If so, implement them. If not, explain why not.
//

#include "ex14_15.h"

int main() {
    Book cp5_1(1234, "CP5", "Lippmen", "2012", 5);
    Book cp5_2(1234, "CP5", "Lippmen", "2012", 5);
    std::cout << cp5_1 + cp5_2 << std::endl;

    return 0;
}
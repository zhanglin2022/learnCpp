// Exercise 14.5
//
// @See Exercise 7.40
//
// Decide what, if any, overloaded operators Book class should provide.
//

#include "ex14_05.h"

int main() {
    Book a(1234, "a1", "a2", "2016");
    Book b;
    std::cin >> b;
    std::cout << b << std::endl;
    std::cout << (a == b) << std::endl;

    return 0;
}

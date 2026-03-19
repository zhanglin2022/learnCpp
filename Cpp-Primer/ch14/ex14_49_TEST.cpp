// Exercise 14.49
//
// @See Exercise 14.25
//
// Regardless of whether it is a good idea to do so, define a 
// conversion to bool for the class from the previous exercise.
//

#include "ex14_49.h"

int main() {
    Book cp5(1234, "CP5", "Lippmen", "2012", 5);
    std::cout << static_cast<bool>(cp5) << std::endl;

    return 0;
}

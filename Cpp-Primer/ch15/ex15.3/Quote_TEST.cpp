// Exercise 15.3
//
// Define your own versions of the Quote class and the print_total function.
// 

#include "../ex15.3/Quote.h"

int main() {
    Quote book("1234", 25.5);
    print_total(std::cout, book, 5);
    return 0;
}

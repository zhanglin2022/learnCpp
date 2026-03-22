// Exercise 15.1
//
// Define your own versions of the Quote class and the print_total function.
// 

#include "ex15_01_Quote.h"

void print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    std::cout << "ISBN: " << item.isbn()
              << " # sold: " << n
              << " total due: " << ret << std::endl;
}

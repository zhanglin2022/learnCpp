// Exercise 15.3
//
// Define your own versions of the Quote class and the print_total function.
// 

#include "Quote.h"

void print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    std::cout << "ISBN: " << item.isbn()
              << " # sold: " << n
              << " total due: " << ret << std::endl;
}

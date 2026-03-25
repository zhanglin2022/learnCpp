// Exercise 15.6
// 
// @See Exercise 15.3
//
// Test your print_total function from the exercises in § 15.2.1 (p. 595)
// by passing both Quote and Bulk_quote objects o that function.
//

#include "quote.h"

void print_total(std::ostream &os, const Quote &item, std::size_t n) {
    double ret = item.net_price(n);
    std::cout << "ISBN: " << item.isbn()
              << " # sold: " << n
              << " total due: " << ret << std::endl;
}

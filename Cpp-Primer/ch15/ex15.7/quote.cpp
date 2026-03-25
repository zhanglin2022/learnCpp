#include "quote.h"

void print_total(std::ostream &os, const Quote &item, std::size_t n) {
    double ret = item.net_price(n);
    std::cout << "ISBN: " << item.isbn()
              << " # sold: " << n
              << " total due: " << ret << std::endl;
}

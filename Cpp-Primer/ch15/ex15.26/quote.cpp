#include "quote.h"

void Quote::debug() const {
    std::cout << "data members of this class:\n"
              << "BookNo: " << this->isbn() << " "
              << "price: " << this->price << " ";
}

void print_total(std::ostream &os, const Quote &item, std::size_t n) {
    double ret = item.net_price(n);
    std::cout << "ISBN: " << item.isbn()
              << " # sold: " << n
              << " total due: " << ret << std::endl;
}

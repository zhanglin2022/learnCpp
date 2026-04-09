#include "limit_quote.h"

double Limit_quote::net_price(std::size_t n) const {
    if (n <= max_qty) 
        return n * (1 - discount) * price;
    else 
        return max_qty * (1 - discount) * price + (n - max_qty) * price;
}

void Limit_quote::debug() const {
    Quote::debug();
    std::cout << "max_qty: " << this->max_qty << " "
              << "discount: " << this->discount << " ";
}
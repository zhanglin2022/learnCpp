#include "limit_quote.h"

double Limit_quote::net_price(std::size_t n) const {
    if (n <= quantity) 
        return n * (1 - discount) * price;
    else 
        return quantity * (1 - discount) * price + (n - quantity) * price;
}

void Limit_quote::debug() const {
    Quote::debug();
    std::cout << "max_qty: " << this->quantity << " "
              << "discount: " << this->discount << " ";
}

#include "limit_quote.h"

double Limit_quote::net_price(std::size_t n) const {
    if (n <= max_qty) 
        return n * (1 - discount) * price;
    else 
        return max_qty * (1 - discount) * price + (n - max_qty) * price;
}

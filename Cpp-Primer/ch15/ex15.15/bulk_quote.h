#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &b, double p, std::size_t qty, double disc) : 
        Disc_quote(b, p, qty, disc) { }
    
    double  net_price(std::size_t) const override;
    void    debug() const override;
};

#endif

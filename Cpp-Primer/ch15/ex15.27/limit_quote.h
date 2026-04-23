#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H

#include "disc_quote.h"

class Limit_quote: public Disc_quote {
public:
    Limit_quote() = default;
    Limit_quote(const std::string &b, double p, std::size_t qty, double disc):
        Disc_quote(b, p, qty, disc) { }

    double  net_price(std::size_t) const override;
    void    debug() const override;
};

#endif

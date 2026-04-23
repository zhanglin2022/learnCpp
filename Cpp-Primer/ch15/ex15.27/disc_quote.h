#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "quote.h"

class Disc_quote: public Quote {
public:
    Disc_quote() { std::cout << "Disc_quote default constructor" << std::endl; }
    Disc_quote(const std::string &b, double p, std::size_t qty, double disc):
        Quote(b, p), quantity(qty), discount(disc) { 
        std::cout << "Disc_quote 4 parameters constructor" << std::endl;
    }

    // copy constructor
    Disc_quote(const Disc_quote &dq) : Quote(dq), quantity(dq.quantity), discount(dq.discount) {
        std::cout << "Disc_quote copy constructor" << std::endl;
    }

    // move constructor
    Disc_quote(Disc_quote &&dq) noexcept :
        Quote(std::move(dq)), quantity(std::move(dq.quantity)), discount(std::move(dq.discount)) {
        std::cout << "Disc_quote : move constructor" << std::endl;
    }

    // copy assignment
    Disc_quote& operator=(const Disc_quote &rhs) {
        if (this != &rhs) {
            Quote::operator =(rhs);
            quantity = rhs.quantity;
            discount = rhs.discount;
        }
        std::cout << "Disc_quote copy assignment" << std::endl;

        return *this;
    }

    // move assignment
    Disc_quote& operator=(Disc_quote &&rhs) noexcept
    {
        if (this != &rhs) {
            Quote::operator =(std::move(rhs));
            quantity = std::move(rhs.quantity);
            discount = std::move(rhs.discount);
        }
        std::cout << "Disc_quote move assignment" << std::endl;

        return *this;
    }

    virtual double net_price(std::size_t) const override = 0;

    ~Disc_quote() {
        std::cout << "Disc_quote destructor" << std::endl;
    }

protected:
    std::size_t  quantity = 0;
    double       discount = 0.0;
};

#endif
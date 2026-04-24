#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() { std::cout << "Bulk_quote default constructor" << std::endl; }
    // Bulk_quote(const std::string &b, double p, std::size_t qty, double disc) : 
    //     Disc_quote(b, p, qty, disc) { 
    //     std::cout << "Bulk_quote 4 parameters constructor" << std::endl;
    // }

    using Disc_quote::Disc_quote;
    
    // copy constructor
    Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq) {
        std::cout << "Bulk_quote copy constructor" << std::endl;
    }

    // move constructor
    Bulk_quote(Bulk_quote &&bq) noexcept : Disc_quote(std::move(bq)) {
        std::cout << "Bulk_quote move constructor" << std::endl;
    }

    // copy assignment
    Bulk_quote& operator=(const Bulk_quote &rhs) {
        if (this != &rhs) {
            Disc_quote::operator=(rhs);
        }
        std::cout << "Bulk_quote copy assignment" << std::endl;

        return *this;
    }

    // move assignment
    Bulk_quote& operator=(Bulk_quote &&rhs) noexcept {
        if (this != &rhs) {
            Disc_quote::operator=(std::move(rhs));
        }
        std::cout << "Bulk_quote move assignment" << std::endl;

        return *this;
    }

    double  net_price(std::size_t) const override;
    void    debug() const override;

    ~Bulk_quote() {
        std::cout << "Bulk_quote destructor" << std::endl;
    }
};

#endif

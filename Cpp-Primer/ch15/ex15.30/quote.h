#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

class Quote {
public:
    Quote() { std::cout << "Quote default constructor "<< std::endl;}
    Quote(const std::string &b, const double p) : bookNo(b), price(p) { 
        std::cout << "Quote 2 parameters constructor " << std::endl; 
    }
    
    // copy constructor
    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) { 
        std::cout << "Quote copy constructor" << std::endl; 
    }

    // move constructor
    Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)) { 
        std::cout << "Quote move constructor" << std::endl; 
    }

    // copy assignment
    Quote& operator=(const Quote &rhs) {
        if (this != &rhs) {
            bookNo = rhs.bookNo;
            price = rhs.price;
        }
        std::cout << "Quote copy assignment" << std::endl;

        return *this;
    }

    Quote& operator=(Quote &&rhs) noexcept {
        if (this != &rhs) {
            bookNo = std::move(rhs.bookNo);
            price = std::move(rhs.price);
        }
        std::cout << "Quote move assignment" << std::endl;

        return *this;
    }

    // clone self
    virtual Quote*  clone() const & { return new Quote(*this); }
    virtual Quote*  clone() && { return new Quote(std::move(*this)); }

    std::string     isbn() const { return bookNo; }
    virtual double  net_price(std::size_t n) const { return n * price; }
    virtual void    debug() const;
    
    virtual ~Quote() {
        std::cout << "Quote destructor" << std::endl;
    }

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

double print_total(std::ostream&, const Quote&, std::size_t);

#endif

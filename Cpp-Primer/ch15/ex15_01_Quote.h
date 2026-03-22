// Exercise 15.1
//
// Define your own versions of the Quote class and the print_total function.
// 

#ifndef EX15_01_H
#define EX15_01_H

#include <string>
#include <iostream>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &b, const double p) : 
        bookNo(b), price(p) { }
    
    std::string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }

    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

void print_total(std::ostream&, const Quote&, size_t);

#endif

// Exercise 15.6
// 
// @See Exercise 15.3
//
// Test your print_total function from the exercises in § 15.2.1 (p. 595)
// by passing both Quote and Bulk_quote objects o that function.
//

#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &b, const double p) : 
        bookNo(b), price(p) { }
    
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }

    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

void print_total(std::ostream&, const Quote&, std::size_t);

#endif

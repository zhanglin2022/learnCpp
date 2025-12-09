// Exercise 7.12
//
// Move the definition of the Sales_data constructor that takes an istream 
// into the body of the Sales_data class.
//

#ifndef EX7_12_H
#define EX7_12_H

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;

struct Sales_data;
istream &read (istream&, Sales_data&);

struct Sales_data {
    Sales_data() = default;
    Sales_data(const string &s): bookNo(s) { }
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(istream &is) { read(is, *this);}

    const std::string &isbn() const { return bookNo; }
    Sales_data& combine (const Sales_data&);
    
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// member functions
Sales_data& Sales_data::combine(const Sales_data& rht) {
    units_sold += rht.units_sold;
    revenue += rht.revenue;
    return *this;
}

// nonmember functions
Sales_data add (const Sales_data &lhs, const Sales_data &rhs ) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

istream &read (istream &is, Sales_data &item) {
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print (ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

#endif
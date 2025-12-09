// Exercise 7.26
//
// Define Sales_data::avg_price as an inline function.
//

#ifndef EX7_26_H
#define EX7_26_H

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;

struct Sales_data;
istream &read (istream&, Sales_data&);

class Sales_data {
    friend istream &read (istream &is, Sales_data &item);
    friend ostream &print (ostream &os, const Sales_data &item);
    friend Sales_data add (const Sales_data &lhs, const Sales_data &rhs);

public: 
    Sales_data() = default;
    Sales_data(const string &s): bookNo(s) { }
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(istream &is) { read(is, *this);}

    const std::string &isbn() const { return bookNo; }
    Sales_data& combine (const Sales_data&);

private:
    inline double avg_price() const { return units_sold ? revenue / units_sold : 0; }

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// member functions
Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// friend functions
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

Sales_data add (const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

#endif

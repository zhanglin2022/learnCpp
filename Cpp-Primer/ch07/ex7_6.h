#ifndef EX7_2_H
#define EX7_2_H

#include <iostream>

using std::istream;
using std::ostream;

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    const std::string &isbn() const { return bookNo; }
    Sales_data& combine (const Sales_data&);
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
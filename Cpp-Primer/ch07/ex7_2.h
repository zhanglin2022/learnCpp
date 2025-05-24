#ifndef EX7_2_H
#define EX7_2_H

#include <iostream>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    std::string isbn() const { return bookNo; }
    Sales_data& combine (const Sales_data&);
};

Sales_data& Sales_data::combine(const Sales_data& rht) {
    units_sold += rht.units_sold;
    revenue += rht.revenue;
    return *this;
}

#endif
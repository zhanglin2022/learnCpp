// Exercise 14.13
//
// @See ex14_02.h 
// 
// Define the substraction operation for class Sales_data.
//

#ifndef EX14_13_H
#define EX14_13_H

#include <iostream>
#include <string>

class Sales_data {
    friend std::istream& operator>>(std::istream&, Sales_data&); // input
    friend std::ostream& operator<<(std::ostream&, const Sales_data&); // output
    friend Sales_data operator+(const Sales_data&, const Sales_data&); // addition
    friend Sales_data operator-(const Sales_data&, const Sales_data&); // substraction
    
public: 
    Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(): Sales_data("", 0, 0) { }
    Sales_data(const std::string &s): Sales_data(s, 0, 0.f) { }
    Sales_data(std::istream&);

    const std::string &isbn() const { return bookNo; }
    Sales_data& operator+=(const Sales_data&); // compound-assignment
    Sales_data& operator-=(const Sales_data&); // compound-assignment

private:
    double avg_price() const;
    
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream& operator>>(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);
Sales_data operator-(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const { 
    return units_sold ? revenue / units_sold : 0; 
}

#endif

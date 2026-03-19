// Exercise 14.45
//
// @See Exercise 14.22
//
// Write conversion operators to convert a Sales_data to string and to double. 
// What values do you think these operators should return?
// 

#ifndef EX14_45_H
#define EX14_45_H

#include <iostream>
#include <string>

class Sales_data {
    friend std::istream& operator>>(std::istream&, Sales_data&); 
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend Sales_data operator-(const Sales_data&, const Sales_data&);
    
public: 
    Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(): Sales_data("", 0, 0) { }
    Sales_data(const std::string &s): Sales_data(s, 0, 0.f) { }
    Sales_data(std::istream&);

    Sales_data& operator=(const std::string&);
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator-=(const Sales_data&);
    explicit operator std::string() const { return bookNo; }
    explicit operator double() const { return avg_price(); }

    const std::string &isbn() const { return bookNo; }

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

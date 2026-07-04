// @See Exercise 14.22

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data {
    friend class std::hash<Sales_data>;
    friend std::istream& operator>>(std::istream&, Sales_data&); 
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend Sales_data operator-(const Sales_data&, const Sales_data&);
    friend bool operator==(const Sales_data&, const Sales_data&);
    friend bool operator!=(const Sales_data&, const Sales_data&);

public: 
    Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(): Sales_data("", 0, 0) { }
    Sales_data(const std::string &s): Sales_data(s, 0, 0.f) { }
    Sales_data(std::istream&);

    const std::string &isbn() const { return bookNo; }
    Sales_data& operator=(const std::string&);
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
bool operator==(const Sales_data&, const Sales_data&);
bool operator!=(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const { 
    return units_sold ? revenue / units_sold : 0; 
}

// specialize std::hash
// note : template specialization should be put in the header!
namespace std {
    template <> 
    struct hash<Sales_data> {
        typedef size_t result_type;
        typedef Sales_data argumet_type;
        size_t operator() (const Sales_data &s) const {
            return hash<std::string>() (s.bookNo) ^
                   hash<unsigned>() (s.units_sold) ^
                   hash<double>() (s.revenue);
        }
    };
} // namespace std

#endif // SALES_DATA_H

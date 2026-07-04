// @See Exercise 14.22

#include "Sales_data.h"

// member function
Sales_data::Sales_data(std::istream &is): Sales_data() { 
    is >> *this;
}

Sales_data& Sales_data::operator=(const std::string &isbn) {
    *this = Sales_data(isbn);
    return *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data& Sales_data::operator-=(const Sales_data &rhs) {
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
    return *this;
}

// friend functions
std::istream& operator>>(std::istream &is, Sales_data &item) {
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is) 
        item.revenue = price * item.units_sold;
    else 
        Sales_data();
    return is;
}

std::ostream& operator<<(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data diff = lhs;
    diff -= rhs;
    return diff;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn() &&
           lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);
}

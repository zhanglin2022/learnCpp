// Exercise 7.41

// @see ex7_26.h
// Rewrite your own version of the Sales_data class to use delegating constructors. 
// Add a statement to the body of each of the constructors that prints a message 
// whenever it is executed. Write declarations to construct a Sales_data object in 
// every way possible. 
// Study the output until you are certain you understand the order of execution 
// among delegating constructors.
//

#ifndef EX7_41_H
#define EX7_41_H

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

struct Sales_data;
istream &read (istream&, Sales_data&);

class Sales_data {
    friend istream &read (istream &is, Sales_data &item);
    friend ostream &print (ostream &os, const Sales_data &item);
    friend Sales_data add (const Sales_data &lhs, const Sales_data &rhs);

public: 
    Sales_data(const string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) 
    { cout << "Sales_data(const string&, unsigned, double)" << endl; }
    
    Sales_data(): Sales_data("", 0, 0) 
    { cout << "Sales_data()" << endl; }
    
    Sales_data(const string &s): Sales_data(s, 0, 0) 
    { cout << "Sales_data(const string&)" << endl; }

    Sales_data(istream &is): Sales_data() 
    { cout << "Sales_data(istream &is)" << endl; read(is, *this); }

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

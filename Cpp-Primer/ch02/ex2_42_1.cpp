// Exercise 2.42
//
// Write your own version of the Sales_data.h header and use it to rewrite 
// the exercise from § 2.6.2(p. 76)
// 

#include<iostream>
#include "ex2_42.h"

// 1.5.1 Read and Writing Sales_data using the head file
int main() {
    Sales_data book;
    double price;
    std::cin >> book.bookNo >> book.units_sold >> price;
    book.calRevenue(price);
    book.printData();

    return 0;
}

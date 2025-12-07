// Exercise 2.42
//
// Write your own version of the Sales_data.h header and use it to rewrite 
// the exercise from § 2.6.2(p. 76)
// 

#include <iostream>
#include "ex2_42.h"

// 1.6 The Bookstore Program using the header file
int main() {
    Sales_data total;
    double totalPrice = 0.0;
    if (std::cin >> total.bookNo >> total.units_sold >> totalPrice) {
        total.calRevenue(totalPrice);
        Sales_data trans;
        double transPrice = 0.0;
        while (std::cin >> trans.bookNo >> trans.units_sold >> transPrice) {
            trans.calRevenue(transPrice);
            if (total.bookNo == trans.bookNo) {
                total.addData(trans);
            } else {
                total.printData();
                total.setData(trans);
            }
        }
        total.printData();
        return 0;
    } else {
        // no input! warn the user 
        std::cerr << "No data?!" << std::endl; 
        return -1; // indicate failure
    }
}

// Exercise 2.42
//
// Write your own version of the Sales_data.h header and use it to rewrite 
// the exercise from § 2.6.2(p. 76)
// 

#include <iostream>
#include "ex2_42.h"

// 1.5.2 Add two Sales_data objects using the head file
int main() {
    Sales_data book1, book2;
    double price1, price2;

    std::cin >> book1.bookNo >> book1.units_sold >> price1;
    std::cin >> book2.bookNo >> book2.units_sold >> price2;
    book1.calRevenue(price1);
    book2.calRevenue(price2);
    
    if (book1.bookNo == book2.bookNo) {
        book1.addData(book2);
        book1.printData();
        return 0;
    } else {
        std::cout << "Data must be the same ISBN." << std::endl;
        return -1;
    }
}
// Exercise 3.1
// 
// Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76) with 
// appropriate using declarations.
//

#include<string>
#include<iostream>
#include "../ch02/ex2_42.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main() {
    // Rewrite 2.6.2 with using declarations.
    Sales_data data1, data2;
    double price;
    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.calRevenue(price);
    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.calRevenue(price);

    if (data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if (totalCnt != 0) 
            cout << totalRevenue / totalCnt << endl;
        else
            cout << "(no sales)" << endl;
        return 0;      
    } else {
        cerr << "Data must refer to the same ISBN" << endl;
        return -1;
    }
}
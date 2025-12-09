// Exercise 7.3
//
// Revise your transaction-processing program from § 7.1.1 (p. 256) to use 
// these members.

#include <iostream>
#include "ex7_02.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main() {
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    } else {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}
// Exercise 8.6
//
// @brief  Rewrite the bookstore program from § 7.1.1 (p. 256) to
//         read its transactions from a file. Pass the name of the
//         file as an argument to main
// @see    "../ch07/ex7_26.h" (Sales_data class)
// @run    give a parameter: "../../data/book.txt"

#include <fstream>
#include <iostream>
#include "../ch07/ex7_26.h"

using std::ifstream;
using std::cout;
using std::endl;
using std::cerr;

int main (int argc, char **argv) {
    ifstream input(argv[1]);
    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn()) 
                total.combine(trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No data?!" << endl;
    }
    return 0;
}

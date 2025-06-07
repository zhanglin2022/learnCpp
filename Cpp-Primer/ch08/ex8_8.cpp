// Exercise 8.8
//
// @brief  Rewrite the bookstore program of ex8_7 to append its 
//         output to its given file
// @see    "../ch07/ex7_26.h" (Sales_data class)
// @run    give two parameters: "../../data/book.txt" "./output.txt"
// @output output.txt(The following are contents)
//         0-201-78345-X 5 110
//         0-201-78346-X 9 839.2
//         0-201-78345-X 5 110
//         0-201-78346-X 9 839.2

#include <fstream>
#include <iostream>
#include "../ch07/ex7_26.h"

using std::ifstream;
using std::ofstream;
using std::endl;
using std::cerr;

int main (int argc, char **argv) {
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);
    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn()) 
                total.combine(trans);
            else {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    } else {
        cerr << "No data?!" << endl;
    }
    return 0;
}

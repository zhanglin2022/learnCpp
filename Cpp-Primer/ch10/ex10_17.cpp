// Exercise 10.17
//
// Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a lambda in the 
// call to sort instead of the compareIsbn function.
//

#include "../ch07/ex7_26.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using std::vector; using std::ifstream; using std::cout; using std::endl;

int main() {
    Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("y"), d5("aaaaz");
    vector<Sales_data> svec{d1, d2, d3, d4, d5};
    
    std::sort(svec.begin(), svec.end(), [](const Sales_data &s1, const Sales_data &s2) 
         { return s1.isbn().size() < s2.isbn().size();} );

    for (const auto &s : svec) cout << s.isbn() << " ";
    cout << endl; 
    
    return 0;
}
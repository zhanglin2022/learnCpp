// Exercise 2.40
// 
// Write your own version of the Sales_data class.
//

#include <string>

struct Sales_data {
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double price = 0.0;
    // ...
};

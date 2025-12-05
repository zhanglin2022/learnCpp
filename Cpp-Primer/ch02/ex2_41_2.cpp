// Exercise 2.41
// 
// Use your Sales_data class to rewrite the exercises in §1.5.1(p. 22), 
// § 1.5.2(p. 24), and § 1.6(p. 25). For now, you should define
// your Sales_data class in the same file as your main function.
//

#include <string>
#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// 1.5.2 Add two Sales_data objects
int main() {
    // Adding Sales_data
    Sales_data data1, data2;
    double price1, price2;
    std::cin >> data1.bookNo >> data1.units_sold >> price1;
    std::cin >> data2.bookNo >> data2.units_sold >> price2;
    data1.revenue = data1.units_sold * price1;
    data2.revenue = data2.units_sold * price2;

    if (data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        std::cout << data1.bookNo << " " << totalCnt
                  << " " << totalRevenue << " ";
        if (totalCnt != 0) {
            std::cout << totalRevenue / totalCnt << std::endl;
        } else {
            std::cout << "(no sales)" << std::endl;
        }
        return 0;
    } else {
        std::cout << "Data must be the same ISBN." << std::endl;
        return -1;
    }
}

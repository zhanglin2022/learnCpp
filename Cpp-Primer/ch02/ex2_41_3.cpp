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

// 1.6 The Bookstore Program
int main() {
    Sales_data total;
    double totalPrice = 0.0;
    if (std::cin >> total.bookNo >> total.units_sold >> totalPrice) {
        total.revenue = total.units_sold * totalPrice;
        Sales_data trans;
        double transPrice = 0.0;
        while (std::cin >> trans.bookNo >> trans.units_sold >> transPrice) {
            trans.revenue = trans.units_sold * transPrice;
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                std::cout << total.bookNo << " " << total.units_sold
                          << " " << total.revenue << " ";
                if (total.units_sold != 0) {
                    std::cout << total.revenue / total.units_sold << std::endl;
                } else {
                    std::cout << "(no sales)" << std::endl;
                }
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        std::cout << total.bookNo << " " << total.units_sold
                  << " " << total.revenue << " ";
        if (total.units_sold != 0) {
            std::cout << total.revenue / total.units_sold << std::endl;
        } else {
            std::cout << "(no sales)" << std::endl;
        }
        return 0;
    } else {
        // no input! warn the user 
        std::cerr << "No data?!" << std::endl; 
        return -1; // indicate failure
    }
}

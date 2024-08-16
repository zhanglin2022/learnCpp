#include <string>
#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// 1.5.1 Read and Writing Sales_data
int main() {
    Sales_data book;
    double price;
    std::cin >> book.bookNo >> book.units_sold >> price;
    book.revenue = book.units_sold * price;
    std::cout << book.bookNo << book.units_sold << book.revenue;
    return 0;
}

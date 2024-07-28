// Reads a set of book sales transactions, and writing each transaction to the standard output

#include <iostream>
#include "../include/Sales_item.h"

int main() {
    for (Sales_item item ; std::cin >> item ; std::cout << item)
    // Sales_item item;
    // while (std::cin >> item) {
    //     std::cout << item;
    // }
    return 0;
}
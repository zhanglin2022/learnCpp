// Exercise 1.22
//
// Write a program that reads several transactions for the same ISBN. Write 
// the sum of all the transactions that were read.
//

#include <iostream>
#include "../include/Sales_item.h"

int main() {
    Sales_item sum, cur_item;

    if (std::cin >> sum) {
        while (std::cin >> cur_item) {
            if (cur_item.isbn() == sum.isbn()) {
                sum += cur_item;
            }
            else {
                std::cout << sum << std::endl;
                sum = cur_item;
            }
        }
        std::cout << sum << std::endl;
    }
    else {
        std::cerr << "No data" << std::endl;
        return -1;
    }
    return 0;
}
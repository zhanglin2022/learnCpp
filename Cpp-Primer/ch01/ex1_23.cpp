// Read several transactions and counts how many transactions occur for each ISBN

#include <iostream>
#include "../include/Sales_item.h"

int main() {
    Sales_item cur_item, val_item;

    if (std::cin >> cur_item) {
        int cnt = 1;
        while (std::cin >> val_item) {
            if (val_item.isbn() == cur_item.isbn()) {
                cnt += 1;
            }
            else {
                std::cout << cur_item << " occurs " << cnt << " transactions." << std::endl;
                cur_item = val_item;
                cnt = 1;

            }
        }
        std::cout << cur_item << " occurs " << cnt << " transactions." << std::endl;
    }
    else {
        std::cerr << "No data" << std::endl;
        return -1;
    }
    return 0;
}
#include "Sales_data.h"

#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<Sales_data> mset;
    Sales_data ele{"Sum", 10, 10.99};

    mset.emplace(ele);
    mset.emplace("Moon", 12, 2.99);

    for ( const auto &item : mset) 
        std::cout << "The hash code of " << item.isbn()
                  << ":\n0x" << std::hex << std::hash<Sales_data>()(item)
                  << "\n";
    return 0;
}

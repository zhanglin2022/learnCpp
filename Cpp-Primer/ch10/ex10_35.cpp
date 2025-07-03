#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    for (auto beg=vec.cend() - 1; beg != vec.cbegin() - 1; --beg)
        std::cout << *beg << " ";
    std::cout << std::endl;

    return 0;
}
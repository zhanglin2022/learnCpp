#include <iostream>
#include <list>
#include <algorithm>

int main() {
    std::list<int> lst{9, 1, 5, 6, 4, 0, 2};
    auto it = std::find(lst.crbegin(), lst.crend(), 0);
    std::cout << *it << std::endl;
    std::cout << std::distance(it, lst.crend()) << std::endl;

    return 0;
}
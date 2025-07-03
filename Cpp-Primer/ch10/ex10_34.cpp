#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    for (auto rbeg=vec.crbegin(); rbeg != vec.crend(); ++rbeg)
        std::cout << *rbeg << " ";
    std::cout << std::endl;

    return 0;
}
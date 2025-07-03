#include <iostream>
#include <list>

void elimDups(std::list<int> &lst) {
    lst.sort();
    lst.unique();
}

int main() {
    std::list<int> lst{0, 0, 1, 2, 2, 3, 4, 5, 5};
    elimDups(lst);
    for (auto i : lst) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
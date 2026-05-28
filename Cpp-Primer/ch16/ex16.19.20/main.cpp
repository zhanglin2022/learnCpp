#include <iostream>
#include <vector>

// ex16.19
template <typename Container>
std::ostream& print(std::ostream &os, const Container &container) {
    for (typename Container::size_type idx = 0; idx != container.size(); ++idx)
        os << container[idx] << " ";
    return os;
} 

// ex16.20
template <typename Container>
std::ostream& print2(std::ostream &os,const Container &container) {
    for (auto iter = container.begin(); iter != container.end(); ++iter)
        os << *iter << " ";
    return os;
} 

int main() {
    std::vector<int> ivec{1, 3, 4, 7};
    print(std::cout, ivec) << std::endl;
    print2(std::cout, ivec) << std::endl;

    return 0;
}

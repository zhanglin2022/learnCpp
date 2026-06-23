#include <iostream>
#include <vector>
#include <utility>

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {
    return f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void func_lvalue(int &lhs, int &rhs) {
    std::cout << lhs << " " << rhs << std::endl;
}

void func_rvalue(int &&lhs, int &&rhs) {
    std::vector<int> ivec;
    ivec.reserve(3);
    ivec.push_back(lhs);
    ivec.push_back(0);
    ivec.push_back(rhs);

    for (auto i : ivec) std::cout << i << " ";
    std::cout << std::endl;
 }

int main() {
    int i = 10, j = 12;
    flip(func_lvalue, i, j);
    flip(func_rvalue, 25, 36);

    return 0;
}


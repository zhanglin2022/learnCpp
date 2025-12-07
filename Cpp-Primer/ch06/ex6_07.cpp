#include <iostream>

size_t count_calls() {
    static size_t cnt = 0;
    return cnt++; // right. return 0, 1, 2
    // return ++cnt; // wrong. return 1, 2, 3
}

int main() {
    for (size_t i = 0; i != 3; ++i) 
        std::cout << count_calls() << std::endl;
    return 0;
}
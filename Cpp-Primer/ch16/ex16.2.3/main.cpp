#include <iostream>
#include <string>

class Sales_data { };

template <typename T>
int compare(const T &v1, const T &v2) {
    if (std::less<T>() (v1, v2)) return -1;
    if (std::less<T>() (v2, v1)) return 1;
    return 0;
}

int main() {
    int i = 9, j = 10;
    std::string s1{"red"}, s2{"orange"};
    Sales_data data1, data2;

    std::cout << compare(i, j) << std::endl;
    std::cout << compare(s1, s2) << std::endl;
    // error: no match for ‘operator<’ (operand types are ‘const Sales_data’ and ‘const Sales_data’)
    // std::cout << compare(data1, data2) << std::endl;

    return 0;
}

#include <iostream>

template <typename T>
std::ostream& print(std::ostream &os, const T &t) {
    return os << t;
}

template <typename T, typename ... Args>
std::ostream& print(std::ostream &os, const T &t, const Args& ... rest) {
    os << t << ", ";
    return print(os, rest...);
}

int main() {
    print(std::cout, 1) << std::endl;
    print(std::cout, 3.14, "pai") << std::endl;
    print(std::cout, "C++", "Primer", "5th", 1, 2) << std::endl;

    return 0;
}
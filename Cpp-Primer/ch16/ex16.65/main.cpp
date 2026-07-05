#include <iostream>
#include <sstream>
#include <string>

// declare first
template <typename T> std::string debug_rep(T *t);
template <> std::string debug_rep(const char *str);
template <> std::string debug_rep(char* str);

// template
template <typename T>
std::string debug_rep(T *t) {
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

// template specialization T = const char *
template <>
std::string debug_rep(const char *str) {
    return std::string(str);
}

// template specialization T = char*
template <>
std::string debug_rep(char *str) {
    return std::string(str);
}

int main() {
    std::string str("C++");
    std::string *ps = &str;

    std::cout << debug_rep(ps) << std::endl;
    std::cout << debug_rep("Primer") << std::endl;

    return 0;
}

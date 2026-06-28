#include <iostream>
#include <sstream>

// always declare first
template <typename T> std::string debug_rep(const T &t);
template <typename T> std::string debug_rep(T *p);

std::string debug_rep(const std::string &s);
std::string debug_rep(char* p);
std::string debug_rep(const char *p);

// print any type we don't otherwise handle
template <typename T>
std::string debug_rep(const T &t) {
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

// print pointers as their pointer value, followed by the object to which the pointer points
template <typename T>
std::string debug_rep(T *p) {
    std::ostringstream ret;
    ret << "pointer: " << p;
    if (p)
        ret << " " << debug_rep(*p);
    else 
        std::cout << " null pointer";
    return ret.str();
}

// non-template version
std::string debug_rep(const std::string &s) {
    return '"' + s + '"';
}

// convert character pointers to string and call the string version of debug_rep
std::string debug_rep(char *p) {
    return debug_rep(std::string(p));
}

std::string debug_rep(const char *p) {
    return debug_rep(std::string(p));
}

// print
template <typename T>
std::ostream& print(std::ostream &os, const T &t) {
    return os << t;
}

template <typename T, typename ... Args>
std::ostream& print(std::ostream &os, const T &t, const Args&... rest) {
    os << t << ", ";
    return print(os, rest...);
}

// errorMsg
template <typename... Args>
std::ostream& errorMsg(std::ostream &os, const Args&... rest) {
    return print(os, debug_rep(rest)...);
}

int main() {
    errorMsg(std::cout, 1, 3, "Cpp", 3.14) << std::endl;
    return 0;
}

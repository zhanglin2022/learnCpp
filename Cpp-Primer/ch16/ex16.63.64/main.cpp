#include <iostream>
#include <vector>
#include <string>
#include <cstring>

// template
template <typename T>
size_t count(std::vector<T> const& vec, T val) {
    size_t count = 0;
    for (auto const& elem : vec)
        if (elem == val) ++count;
    return count;
}

// template specialization
template <>
size_t count(std::vector<const char*> const& vec, const char* value) {
    size_t count = 0;
    for (auto const& elem : vec)
        if (strcmp(elem, value) == 0) ++count;
    return count;
}

int main() {
    // ex16.63
    std::vector<double> dvec{3.14, 2.3, 4.7};
    std::vector<int> ivec{1, 2, 4, 6, 2, 2, 1};
    std::vector<std::string> svec{"Sun", "Moon", "Star", "Moon", "Moon"};
    std::cout << count(dvec, 3.14) << "\n"
              << count(ivec, 2) << "\n"
              << count(svec, std::string("Moon")) << "\n";          
    
    // ex16.64 
    std::vector<const char*> csvec{"C++", "Primer", "5th"};
    std::cout << count(csvec, "C++") << "\n";

    return 0;
}

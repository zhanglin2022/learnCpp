#include <iostream>
#include <string>
#include <list>
#include <vector>

namespace ch16 {
    template<typename Iterator, typename Value>
    Iterator find(Iterator beg, Iterator end, Value const &value) {
        for (Iterator it = beg; it != end; ++it)
            if (*it == value) return it;
        return end;
    }
}

int main() {
    std::vector ivec{1, 3, 5, 7};
    auto is_in_vector = ivec.cend() != ch16::find(ivec.cbegin(), ivec.cend(), 5);
    std::cout << (is_in_vector ? "found\n" : "not found\n");

    std::list<std::string> l{"Cpp", "Primer"};
    auto is_in_list = l.cend() != ch16::find(l.cbegin(), l.cend(), "5th");
    std::cout << (is_in_list ? "found\n" : "not found\n");

    return 0;
}

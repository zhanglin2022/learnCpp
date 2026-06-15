#include <iostream>
#include <string>

template <typename Arr>
void print(Arr const &arr) {
    for (auto ele : arr)
        std::cout << ele << std::endl;
}

int main() {
    std::string sa[] = {"C++", "Primer", "5th"};
    int ia[] = {2, 4, 6};
    print(sa);
    print(ia);
    
    return 0;
}

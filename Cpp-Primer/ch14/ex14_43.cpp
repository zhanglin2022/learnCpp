// Exercise 14.43
//
// Using library function objects, determine whether a given int value is 
// divisible by any element in a container of ints.
//

#include <iostream>
#include <vector>
#include <algorithm>

using std::placeholders::_2;

int main() {
    std::vector<int> ivec{2, 3, 5};
    int input;
    std::cin >> input;
    std::modulus<int> mod;
    auto predicator = [&](int x) { return 0 == mod(input, x); };
    auto is_divisible = std::any_of(ivec.cbegin(), ivec.cend(), predicator);
    std::cout << (is_divisible ? "Yes" : "No") << std::endl;

    return 0;
}
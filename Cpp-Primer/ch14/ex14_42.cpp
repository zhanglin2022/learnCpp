// Exercise 14.42
//
// Using library function objects and adaptors, define an expression to
// (a) Count the number of values that are greater than 1024
// (b) Find the first string that is not equal to pooh
// (c) Multiply all values by 2

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::placeholders::_1;
int main() {
    std::vector<int> ivec{1, 2000, 5, 3000};
    auto num = std::count_if(ivec.cbegin(), ivec.cend(), std::bind(std::greater<int>(), _1, 1024));
    std::cout << num << std::endl;

    std::vector<std::string> svec{"pooh", "little", "car"};
    auto it = std::find_if(svec.cbegin(), svec.cend(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
    std::cout << *it << std::endl;

    auto multi = std::transform(ivec.begin(), ivec.end(), ivec.begin(), std::bind(std::multiplies(), _1, 2));
    for (int i : ivec) std::cout << i << " ";
    std::cout << std::endl;
    
    return 0;
}
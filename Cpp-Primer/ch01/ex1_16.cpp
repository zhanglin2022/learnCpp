// Print the sum of a set of integers read from cin(use for)

#include <iostream>

int main() {
    int sum = 0;

    for(int val = 0; std::cin >> val; sum += val)
    std::cout << "The sum is: " << sum << std::endl;
    return 0;
} 
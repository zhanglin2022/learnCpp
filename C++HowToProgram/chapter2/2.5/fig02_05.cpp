#include <iostream>

int main() {
    int number1{0}; // first integer to add (initialized to 0)
    int number2{0};
    int sum{0};

    std::cout << "Enter the first integer: ";
    std::cin >> number1; // read first integer from user into number1

    std::cout << "Enter the firsr integer: ";
    std::cin >> number2;

    sum = number1 + number2;

    std::cout << "Sum is " << sum << std::endl; // display sum; end line
}
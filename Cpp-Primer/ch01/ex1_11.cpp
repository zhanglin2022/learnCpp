// Exercise 1.11
//
// Write a program that prompts the user for two integers. Print each number 
// in the range specified by those two integers.
//

#include<iostream>

void printrange(int low, int high) {
    if(low > high) {
        printrange(high, low);
    }
    while (low <= high) {
        std::cout << low++ << " ";
    }
}

int main() {
    int low = 0, high = 0;
    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> low >> high;
    printrange(low, high);
    return 0;
}
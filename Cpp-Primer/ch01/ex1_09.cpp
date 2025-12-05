// Exercise 1.9
// 
// Write a program that uses a while to sum the numbers from 50 to 100.
//

#include <iostream>

 auto sum(int low, int high) {
    int sum = 0;
    while (low <= high) {
        sum += low;
        low++;
    }
    return sum;
}

int main() {
    std::cout << "The sum of 50 to 100 inclusive is: " << sum(50, 100) << std::endl;
    return 0;
}

// sum the numbers from 50 to 100 (use while)

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

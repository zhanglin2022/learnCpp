// Print the range of two numbers

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
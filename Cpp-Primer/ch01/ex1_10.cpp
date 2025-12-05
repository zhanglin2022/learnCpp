// Exercise 1.10
// 
// In addition to the ++ operator that adds 1 to its operand, there is a 
// decrement operator (--) that subtracts 1. Use the decrement operator to 
// write a while that prints the numbers from ten down to zero.
//

#include<iostream>

void dePrint(int high, int low) {
    while (high >= low) {
        std::cout << high-- << " ";
    }
}

int main() {
    dePrint(10, 0);
    return 0;
}

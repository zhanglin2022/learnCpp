// Print numbers from ten down to zero using the decrement operator

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

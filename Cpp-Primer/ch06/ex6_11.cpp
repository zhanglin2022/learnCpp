// Exercise 6.11
//
// Write and test your own version of reset that takes a reference.
// 

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void reset(int &i) {
    i = 0;
}

int main() {
    for(int i = 0; cout << "Enter a number: \n", cin >> i;) {
        reset(i);
        cout << i << endl;
    }
    return 0;  
}

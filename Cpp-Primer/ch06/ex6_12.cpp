// Exercise 6.12
// 
// Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use references 
// instead of pointers to swap the value of two ints. 
// Which version do you think would be easier to use and why?
//

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    for(int i, j; cout << "Enter two numbers: \n", cin >> i >> j;) {
        swap(i, j);
        cout << i << " " << j << endl;
    }
    return 0;
}
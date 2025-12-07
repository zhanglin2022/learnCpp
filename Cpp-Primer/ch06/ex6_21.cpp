// Exercise 6.21
// Write a function that takes an int and a pointer to an int and 
// returns the larger of the int value or the value to which the 
// pointer points. 
// What type should you use for the pointer?
//

#include <iostream>

using std::cout;
using std::endl;

int larger_one(const int i, const int *const p) {
    return (i >= *p) ? i : *p;
}

int main() {
    int i = 5;
    cout << "The larger one is: " << larger_one(3, &i) << endl;
    return 0;
}

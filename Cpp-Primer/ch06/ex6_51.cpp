// Exercise 6.51
//
// Write all four versions of f. Each function should print a distinguishing 
// message. Check your answers for the previous exercise. 
// If your answers were incorrect, study this section until you understand why 
// your answers were wrong.

#include <iostream>

using std::cout;
using std::endl;

void f () {
    cout << "f()" << endl;
};

void f (int i) {
    cout << "f(int)" << endl;
}

void f (int lft, int rht) {
    cout << "f(int, int)" << endl;
} 

void f (double lft, double rht = 3.14) {
    cout << "f(double, double)" << endl;
}

int main() {
    // f(2.56, 42); // error: `f` is ambiguous
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    
    return 0;
}
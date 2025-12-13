// Exercise 12.16
//
// Compilers don’t always give easy-to-understand error messages if we attempt to copy 
// or assign a unique_ptr. 
// Write a program that contains these errors to see how your compiler diagnoses them.
//

#include <iostream>
#include <memory>

using std::unique_ptr; using std::cout; using std::endl;
int main() {
    unique_ptr<int> p1(new int(23));
    // unique_ptr<int> p2(p1);    // error: use of deleted function p1
    // unique_ptr<int> p3 = p1;   // error: use of deleted function p1
    cout << *p1 << endl;
    
    return 0;
}
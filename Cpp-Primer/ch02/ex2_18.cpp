// Exercise 2.18
//
// Write code to change the value of a pointer. Write code to change the 
// value to which the pointer points.
//

#include<iostream>

int main() {
    int val1 = 10, val2 = 20;
    int *p1 = &val1, *p2 = p1;
    // change the value of a pointer
    p1 = &val2;
    // change the valuetowhichthepointerpoint
    *p2 = val2;
    return 0;
}

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

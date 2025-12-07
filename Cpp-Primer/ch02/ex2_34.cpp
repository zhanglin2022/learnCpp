// Exercise 2.34
//
// Write a program containing the variables and assignments from the
// previous exercise.
// Print the variables before and after the assignments to check
// whether your predictions in the previous exercise were correct.
// If not, study the examples until you can convince yourself you know
// what led you to the wrong conclusion.
//

#include <iostream>

int main() {
    int i =0, &r = i;
    const int ci = i, &cr = ci;

    auto a = r;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;
    a = 42;
    b = 42;
    c = 42;
    // d = 42;
    // e = 42;
    // g = 42;
    return 0;
}
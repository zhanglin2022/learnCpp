// Exercise 
// 
// Determine the types deduced in each of the following definitions.
// Once you’ve figured out the types,
// write a program to see whether you were correct.
//

# include <iostream>

int main() {
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;

    return 0;
}
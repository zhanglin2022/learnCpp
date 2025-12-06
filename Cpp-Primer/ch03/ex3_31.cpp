// Exercise 3.31
//
// Write a program to define an array of ten ints. Give each element the 
// same value as its position in the array.
//

#include <iostream>

using std::cout;
using std::endl;

int main() {
    constexpr size_t arrary_size = 10;
    int ia[arrary_size];
    for (size_t ix = 0; ix < arrary_size; ++ix)
        ia[ix] = ix;
    for (auto i : ia)
        cout << i << " ";
    cout << endl;
    return 0;
}
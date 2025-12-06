// Exercise 3.32
//
// Copy the array you defined in the previous exercise into another array. 
// Rewrite your program to use vectors
//

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main() {
    constexpr size_t size = 10;
    // array
    int arr1[size];
    for (size_t ix = 0; ix < size; ++ix) arr1[ix] = ix;
    int arr2[size];
    for (size_t ix = 0; ix < size; ++ix) arr2[ix] = arr1[ix];

    // vector
    vector<int> vec1(size);
    for (int i = 0; i < size; ++i) vec1[i] = arr1[i];
    vector<int> vec2(vec1);
    for (auto i : vec2) cout << i << " ";
    cout << endl;

    return 0;
}
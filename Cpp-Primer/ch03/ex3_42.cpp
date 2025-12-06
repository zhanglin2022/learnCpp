// Exercise 3.42
//
// Write a program to copy a vector of ints into an array of ints.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> ivec{1, 2, 5, 7};
    int size = ivec.size();
    int arr[size];
    for (int i = 0; i != size; ++i) {
        arr[i] = ivec[i];
    }
    for (auto i : arr) cout << i << " ";
    cout << endl;

    return 0;
}
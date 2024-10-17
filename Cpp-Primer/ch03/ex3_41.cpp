#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main() {
    int arr[] = {1, 3, 5, 7};
    vector<int> ivec(begin(arr), end(arr)); // [1, 3, 5, 7]
    // vector<int> ivec(arr + 1, arr + 4); // [3, 5, 7]
    for (auto i : ivec) cout << i << " ";
    cout << endl;

    return 0;
}
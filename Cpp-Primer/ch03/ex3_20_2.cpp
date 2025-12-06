// Exercise 3.20
//
// Read a set of integers into a vector. Print the sum of each pair of adjacent elements. 
// Change your program so that it prints the sum of the first and last elements, followed 
// by the sum of the second and second-to-last, and so on.
//

#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<int> ivec;
    for (int num = 0; cin >> num; ivec.push_back(num));
    if (ivec.empty()) {
        cout << "input at least one num" << endl;
        return -1;
    }
    if (ivec.size() == 1) {
        cout << "only one integer " << ivec[0] << ", it doesn't have any adjacent elements." << endl;
        return -1;
    }

    // If the vector has odd size, element in the middle will add to itself.
    auto size = (ivec.size() + 1) / 2;

    for (int i = 0; i < size; ++i)
        cout << ivec[i] + ivec[ivec.size() - i - 1 ] << " ";
    cout << endl;
    return 0;
}
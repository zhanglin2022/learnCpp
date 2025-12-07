// Exercise 3.36
// 
// Write a program to compare two arrays for equality. Write a similar program 
// to compare two vector.
//

#include <iostream>
#include <vector>
#include <iterator>

using std::vector;
using std::cout;
using std::endl;
using std::begin;
using std::end;

// pb point to begin of the array, pe point to end of the array.
bool compare(int* pb1, int* pe1, int* pb2, int* pe2) {
    if ((pe1 - pb1) != (pe2 - pb2)) // different size
        return false;
    else {
        for (int *i = pb1, *j = pb2; (i != pe1) && (j != pe2); ++i, ++j)
            if (*i != *j) return false;
    }
    return true;
}
int main() {
    
    // array
    int arr1[3] = {0, 1, 2};
    int arr2[3] = {0, 1, 3};
    if (compare(begin(arr1), end(arr1), begin(arr2), end(arr2)))
        cout << "The two arrays are equal." << endl;
    else
        cout << "The two arrays are not equal." << endl;
    // vector
    vector<int> vec1 = {0, 1, 3};
    vector<int> vec2 = {0, 1, 3};
    if (vec1 == vec2) 
        cout << "The two vectors are equal." << endl;
    else
        cout << "The two vectors are not equal." << endl;

    return 0;
}
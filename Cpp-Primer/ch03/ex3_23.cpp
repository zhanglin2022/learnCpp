// Exercise 3.23
//
// Write a program to create a vector with ten int elements. Using an iterator, 
// assign each element a value that is twice its current value. Test your program 
// by printing the vector.
//

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> vec(10, 5);
    cout << "The twice vector is: [";
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        (*it) *= 2;
        cout << *it << (it != vec.end() -1 ? "," : "");
    }
    cout << "]" << endl;
    return 0;
}
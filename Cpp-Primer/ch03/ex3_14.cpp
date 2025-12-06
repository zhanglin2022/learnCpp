// Exercise 3.14
//
// Write a program to read a sequence of ints from cin and store those values 
// in a vector
//

#include <vector>
#include <iostream>

using std::vector;
using std::cin;

int main() {
    vector<int> vec;
    for(int num = 0; cin >> num; vec.push_back(num));
    return 0;
}

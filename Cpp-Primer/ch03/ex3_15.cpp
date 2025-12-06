// Exercise 3.15
//
// Repeat the previous program but read strings this time.
// 

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cin;

int main() {
    vector<string> vec;
    for(string word; cin >> word; vec.push_back(word));
    return 0;
}

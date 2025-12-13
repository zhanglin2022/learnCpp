// Exercise 11.11 and 11.13
//
// Write a program to read a sequence of strings and ints, storing each into 
// a pair. Store the pairs in a vector.
//

#include <iostream>
#include <utility>
#include <vector>
#include <string>

using std::vector; using std::pair; using std::string; using std::make_pair;

int main() {
    vector<pair<string, int>> vec;
    int i;
    string str;
    while(std::cin >> str >> i) {
        // vec.push_back(pair<string, int>(str, i));
        // vec.push_back(make_pair(str, i));
        vec.emplace_back(str, i); // easiest way
        // vec.push_back({str, i});
    }

    for (auto const& v : vec) {
        std::cout << v.first << ": " << v.second << std::endl;
    }

    return 0; 
}
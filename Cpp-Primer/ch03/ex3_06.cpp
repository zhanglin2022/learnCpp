// Exercise 3.6
// 
// Use a range for to change all the characters in a string to X

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main() {
    string str("a initial string");
    for (auto &c : str)
        c = 'X';
    cout << str << endl;
    return 0;
}
// Exercise 3.2
//
// Write a program to read the standard input a line at a time. Modify 
// your program to read a word at a time.
// 

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string line;
    // read the standard input a line at a time
    while(getline(cin, line)) {
        cout << line << endl;
    }
    return 0;
}

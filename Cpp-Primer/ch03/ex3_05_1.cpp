// Exercise 3.5
// Write a program to read strings from the standard input, concatenating 
// what is read into one large string. Print the concatenated string. 
// Next, change the program to separate adjacent input strings by a space.
//

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string concatenated;
    for (string str; cin >> str; concatenated += str);
    cout << "The concatenated string is " << concatenated << endl;
    return 0;
}
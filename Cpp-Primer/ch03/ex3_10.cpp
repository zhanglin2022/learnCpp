// Exercise 3.10
//
// Write a program that reads a string of characters including punctuation 
// and writes what was read but with the punctuation removed.
//

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "Enter a string of characters including punctuation" << endl;
    for (string str ; getline(cin, str) ; cout << endl)
        for(auto i : str)
            if(!ispunct(i)) cout << i;
    return 0;
}
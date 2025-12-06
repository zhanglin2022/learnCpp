// Exercise 3.4
//
// Write a program to read two strings and report whether the strings are 
// equal. If not, report which of the two is larger. 
// Now, change the program to report whether the strings have the same length, 
// and if not, report which is longer.
//

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    if (str1 == str2) {
        cout << "The two strings are equal." << endl;;
    } else {
        cout << "The lager string is " << ((str1 >str2) ? str1 : str2);
    }
    return 0;
}
// Exercise 9.47
//
// Write a program that finds each numeric character and then each alphabetic 
// character in the string "ab2c3d7R4E6". 
// Write two versions of the program. The first should use find_first_of, and 
// the second find_first_not_of.
//

#include <iostream>
#include <string>

using std::string; using std::cout; using std::endl;

int main() {
    string s("ab2c3d7R4E6");
    string nums("123456789");
    string apbts("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    // use find_the_first_not_of
    cout << "numeric characters: ";
    for (size_t pos = 0; (pos = s.find_first_not_of(apbts, pos)) != string::npos; ++pos) 
        cout << s[pos] << " ";
    cout << "\nalphabetic characters: ";
    for (size_t pos = 0; (pos = s.find_first_not_of(nums, pos)) != string::npos; ++pos)
        cout << s[pos] << " ";
    cout << endl;

    return 0;
}
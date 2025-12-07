// Exercise 3.39
//
// Write a program to compare two strings. Now write a program to compare 
// the values of two C-style character strings.
//

#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

void compare_string(string s1, string s2) {
    if (s1 == s2) 
        cout << s1 << " = " << s2 << endl;
    else if (s1 > s2)
        cout << s1 << " > " << s2 << endl;
    else
        cout << s1 << " < " << s2 << endl;
}

void compare_cstring(const char* cs1, const char* cs2) {
    auto result = strcmp(cs1, cs2);
    if (result == 0) 
        cout << cs1 << " = " << cs2 << endl;
    else if (result > 0) 
        cout << cs1 << " > " << cs2 << endl;
    else    
        cout << cs1 << " < " << cs2 << endl;
}

int main() {
    // string
    string s1("Moon"), s2("Sun");
    compare_string(s1, s2);

    // cstring
    const char* cs1 = "Cmoon";
    const char* cs2 = "Csun";
    compare_cstring(cs1, cs2);

    return 0;
}
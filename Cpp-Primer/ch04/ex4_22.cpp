// Exercise 4.22
//
// Extend the program that assigned high pass, pass, and fail grades to also 
// assign low pass for grades between 60 and 75 inclusive. 
// Write two versions: One version that uses only conditional operators; the 
// other should use one or more if statements. Which version do you think is 
// easier to understand and why?
//

#include<iostream>
#include<vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main () {

    for (unsigned g; cin >> g;) {
        // condition operators
        cout << ((g > 90) ? "high pass"
                          : (g < 60) ? "fail"
                          : (g < 75) ? "low pass" : "pass") << endl;
        // if statements
        if (g > 90)      cout << "hign pass";
        else if (g < 60) cout << "fail";
        else if (g < 75) cout << "low pass";
        else             cout << "pass";
        cout << endl;
    }    
    return 0;
}
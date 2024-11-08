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
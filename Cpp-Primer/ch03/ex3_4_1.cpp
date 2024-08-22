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
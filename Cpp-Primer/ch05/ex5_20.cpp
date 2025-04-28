#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string str, pre_str;
    while (cin >> str) {
        if (str == pre_str) break;
        else pre_str = str;
    }
    if (cin.eof()) cout << "no word was repeated." << endl;
    else           cout << str << " occurs twice in succession." << endl;

    return 0;
}
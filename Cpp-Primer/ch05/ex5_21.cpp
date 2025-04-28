#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string str, pre_str;
    bool no_twice = true;
    while (cin >> str) {
        if (str == pre_str && str[0] == toupper(str[0])) {
            cout << str << " occurs twice in succession." << endl;
            no_twice = false;
            break;
        }
        pre_str = str;
    }
    if (no_twice) cout << "no word was repeated." << endl;

    return 0;
}
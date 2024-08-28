#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main() {
    string str("a initial string");
    decltype(str.size()) idx = 0;

    // while
    while (idx < str.size()) str[idx++] = 'X';
    cout << str << endl;

    // // for
    // for (idx = 0 ; idx < str.size() ; str[idx++] = 'X');
    // cout << str << endl;

    return 0;
}
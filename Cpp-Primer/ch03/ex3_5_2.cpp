#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string str;
    for (string word ; cin >> word ; str += ((str.empty()) ? "" : " ") + word);
    cout << "The concatenated string is " << str << endl;
    return 0;
}
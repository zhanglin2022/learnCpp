// Exercise 9.46
// 
// Rewrite the previous exercise using a position and length to manage 
// the strings. 
// This time use only the insert function.
//

#include <iostream>
#include <string>

using std::string; using std::cout; using std::endl;

auto add_pre_and_suffix(string name, const string &pre, const string &su) {
    return name.insert(0, pre).insert(name.size(), su);
}

int main() {
    string name("Rebort");
    cout << add_pre_and_suffix(name, "Mr.", ", Jr.") << endl;;
    return 0;
}
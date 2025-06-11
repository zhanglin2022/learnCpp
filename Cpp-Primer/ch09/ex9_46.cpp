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
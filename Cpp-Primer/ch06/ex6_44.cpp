#include  <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

// compare the length of two strings
inline bool isShorter (const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

int main() {
    string s1("sun"), s2("moon"); 
    cout << s1 << " is shorter than " << s2 << " : "
         << isShorter(s1, s2) << endl;
    return 0;
}
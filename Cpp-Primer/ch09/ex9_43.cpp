#include <iostream>
#include <string>

using std::string; using std::cout; using std::endl;

void replace_with(string &s, const string &oldVal, const string &newVal) {
    for (auto cur = s.begin(); cur <= s.end() - oldVal.size();) {
        if (oldVal == string(cur, cur + oldVal.size())) {
            cur = s.erase(cur, cur + oldVal.size());
            cur = s.insert(cur, newVal.begin(), newVal.end());
            cur += newVal.size();
        } else 
            ++cur;  
    } 
}

int main() {
    string s{ "To drive straight thru is a foolish, tho courageous act." };
    replace_with(s, "tho", "though");
    replace_with(s, "thru", "through");
    cout << s << endl;

    return 0;
}

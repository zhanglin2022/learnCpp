#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector; using std::string; using std::count_if; using std::cout; using std::endl;

int main() {
    vector<string> svec{"obliged", "puma", "investigate", "corner"};
    auto i = count_if(svec.begin(), svec.end(), [](const string &i) { return i.size() > 6; });
    cout << i << endl;

    return 0;
}
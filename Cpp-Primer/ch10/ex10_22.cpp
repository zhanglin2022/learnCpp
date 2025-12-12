// Exercise 10.22
// 
// Rewrite the program to count words of size 6 or less using functions 
// in place of the lambdas.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::vector; using std::string; using std::cout; using std::endl;
using std::placeholders::_1;

bool check_size(const string &s, string::size_type sz) {
    return s.size() <= sz;
}

int main() {
    vector<string> svec{"obliged", "puma", "investigate", "corner"};
    auto i = std::count_if(svec.begin(), svec.end(), std::bind(check_size, _1, 6));
    cout << i << endl;

    return 0;
}
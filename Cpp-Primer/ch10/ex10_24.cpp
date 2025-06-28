#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::vector; using std::string; using std::cout; using std::endl;
using std::placeholders::_1;

bool check_size(const string &s, string::size_type sz) {
    return s.size() < sz;
}

int main() {
    vector<int> ivec{1, 3, 5, 7};
    string str("sun");
    auto iter = std::find_if(ivec.begin(), ivec.end(), std::bind(check_size, str, _1));
    if (iter != ivec.end())
        cout << *iter << endl;
    else
        cout << "Not Found" << endl;
    
    return 0;
}
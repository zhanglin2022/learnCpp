#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cin;

int main() {
    vector<string> vec;
    for(string word; cin >> word; vec.push_back(word));
    return 0;
}

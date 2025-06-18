#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::partition; using std::string; using std::cout; using std::endl; using std::vector;

bool comparelen(const string &str) {
    return str.size() >= 5;
}

int main() {
    vector<string> svec{"aaaa", "aaaaa", "333", "666666"};
    auto pivot = partition(svec.begin(), svec.end(), comparelen);

    for (auto it = svec.cbegin(); it != pivot; ++it) cout << *it << " ";
    cout << endl;

    return 0;
}

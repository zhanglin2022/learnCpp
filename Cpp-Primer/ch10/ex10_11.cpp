#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector; using std::string; using std::cout; using std::endl;
using std::stable_sort; using std::sort; using std::unique;

void print(const vector<string> &svec) {
    for (auto &i : svec) cout << i << " ";
    cout << endl;
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

int main() {
    vector<string> svec{"the", "beautiful", "sun", "and", "the",
                        "beautiful", "moon"};
    elimDups(svec);
    stable_sort(svec.begin(), svec.end(), isShorter);
    print(svec);

    return 0;
}
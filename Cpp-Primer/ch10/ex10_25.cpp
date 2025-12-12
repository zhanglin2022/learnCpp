// Exercise 10.25
//
// In the exercises for § 10.3.2 (p. 392) you wrote a version of biggies 
// that uses partition. 
// Rewrite that function to use check_size and bind.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::vector; using std::string; using std::cout; using std::endl;
using std::placeholders::_1;

bool check_size(const string &s, string::size_type sz) {
    return s.size() >= sz;
}

void elimDups(vector<string> &words) {
    std::sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words); 
    auto pivot = std::stable_partition(words.begin(), words.end(), std::bind(check_size, _1, sz));
    for (auto it = words.cbegin(); it != pivot; ++it) cout << *it << " ";
    cout << endl;
}

int main() {
    vector<string> svec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", 
                        "red", "turtle"};
    biggies(svec, 3);

    return 0;
}
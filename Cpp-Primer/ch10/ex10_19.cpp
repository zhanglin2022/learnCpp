#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector; using std::string; using std::cout; using std::endl;

void elimDups(vector<string> &words) {
    std::sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies_stable_partition(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words); 
    auto pivot = std::stable_partition(words.begin(), words.end(), [sz] (const string &str) 
                                { return str.size() >= sz;} );
    for (auto it = words.cbegin(); it != pivot; ++it) cout << *it << " ";
    cout << endl;
}

int main() {
    vector<string> svec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", 
                        "red", "turtle"};
    biggies_stable_partition(svec, 3);

    return 0;
}
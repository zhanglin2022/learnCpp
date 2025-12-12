// Exercise 10.18
// 
// Rewrite biggies to use partition instead of find_if. We described the 
// partition algorithm in exercise 10.13 in § 10.3.1 (p. 387).
//

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

void biggies_partition(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words); 
    auto pivot = std::partition(words.begin(), words.end(), [sz] (const string &str) 
                                { return str.size() >= sz;} );
    for (auto it = words.cbegin(); it != pivot; ++it) cout << *it << " ";
    cout << endl;
}

int main() {
    vector<string> svec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", 
                        "red", "turtle"};
    biggies_partition(svec, 3);

    return 0;
}
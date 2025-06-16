#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector; using std::string; using std::cout; using std::endl;
using std::sort; using std::unique;

void print(const vector<string> &svec) {
    for (auto &i : svec) cout << i << " ";
    cout << endl;
}

vector<string>& elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    print(words);

    auto end_unique = unique(words.begin(), words.end());
    print(words); 

    words.erase(end_unique, words.end());
    return words;
}

int main() {
    vector<string> svec{"the", "beautiful", "sun", "and", "the",
                        "beautiful", "moon"};
    print(svec); 
    print(elimDups(svec));
    
    return 0;
}
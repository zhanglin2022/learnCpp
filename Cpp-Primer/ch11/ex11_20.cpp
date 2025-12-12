// Exercise 11.20
//
// Rewrite the word-counting program from § 11.1 (p. 421) to use insert instead 
// of subscripting. 
// Which program do you think is easier to write and read? Explain your reasoning.
//

#include <iostream>
#include <map>
#include <string>

using std::cin; using std::cout; using std::endl; using std::map; using std::string;

int main() {
    map<string, size_t> word_count; 
    string word; 
    for (string word; cin >> word; ) {
        auto ret = word_count.insert({word, 1});
        if (!ret.second) 
        ++ret.first->second;
    }        
    for (const auto &w : word_count) 
        cout << w.first << ": " << w.second << endl;

    return 0;
}
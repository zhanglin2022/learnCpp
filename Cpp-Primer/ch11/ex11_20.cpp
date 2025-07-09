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
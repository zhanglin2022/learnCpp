// Exercise 11.4
//
// Extend your program to ignore case and punctuation. For example, 
// “example.” “example,” and “Example” should all increment the same 
// counter.
//

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using std::string; using std::remove_if; using std::cin; using std::cout; using std::endl;

using Map = std::map<std::string, size_t>;
using Set = std::set<std::string>;

void print(const Map &m) {
    for (const auto &kv : m) 
        cout << kv.first << " : " << kv.second << endl;
}

string const& strip(string &str) {
    for (auto &ch : str) ch = tolower(ch);
    str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());
    return str;
}

auto strip_and_count (Set const& exclude) {
    Map word_count;
    for (string word; cin >> word; ) {
        if (exclude.find(word) == exclude.end()) ++word_count[strip(word)];
    }
    return word_count;
}

int main() {
    Set exclude = { "The", "But", "And", "Or", "An", "A", "the", "but",
                    "and", "or", "an", "a" };
    print(strip_and_count(exclude));
    
    return 0;
}

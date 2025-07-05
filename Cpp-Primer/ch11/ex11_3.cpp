#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    std::map<std::string, size_t> word_count;
    std::set<std::string> exclude = { "The", "But", "And", "Or", "An", "A", 
                                      "the", "but", "and", "or", "an", "a" };
    
    for (std::string word; std::cin >> word; ) {
        if (exclude.find(word) == exclude.end()) ++word_count[word];
    }

    for (const auto &w : word_count)
        std::cout << w.first << " : " << w.second << std::endl;
    return 0;
}
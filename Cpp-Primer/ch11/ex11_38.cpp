// Exercise 11.38
//
// Rewrite the word-counting (§ 11.1, p. 421) and word-transformation 
// (§ 11.3.6, p. 440) programs to use an unordered_map.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

using std::unordered_map; using std::string; using std::cin; using std::cout;
using std::endl; using std::ifstream; using std::istringstream;

void wordCounting() {
    unordered_map<string, size_t> counts;
    for (string word; cin >> word; ++counts[word]);
    for (const auto &c : counts) 
        cout << c.first << ": " << c.second << endl;
}

void wordTransformation() {
    ifstream ifs_map("../../data/rule_of_transform.txt");
    ifstream ifs_input("../../data/give_to_transform.txt");
    if (!ifs_map || !ifs_input) {
        std::cout << "can't find file documents\n";
        return;
    } 
    unordered_map<string, string> trans_map;
    for (string key, value; ifs_map >> key && getline(ifs_map, value); ) {
        if (value.size() > 1 ) trans_map[key] = value.substr(1).substr(0, value.find_last_not_of(" "));
    }

    for (string text; getline(ifs_input, text); ) {
        istringstream iss(text);
        bool firstword = true;
        for (string word; iss >> word; ) {
            if (firstword) firstword = false;
            else cout << " ";
            auto map_it = trans_map.find(word);
            cout << (map_it == trans_map.cend() ? word : map_it->second);
        }
        cout << endl;
    }
}

int main() {
    // wordCounting();
    wordTransformation();

    return 0;
}
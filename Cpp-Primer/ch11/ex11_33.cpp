#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <exception>

using std::map; using std::string; using std::cout; using std::endl; 
using std::ifstream; using std::runtime_error; using std::istringstream;

void print (map<string, string> &ma) {
    for (auto kv : ma)
        cout << kv.first << ": " << kv.second << endl;
        cout << endl;
}

map<string, string> buildMap (ifstream &map_file) {
    map<string, string> trans_map;
    for (string key, value; map_file >> key && getline(map_file, value); ) {
        if (value.size() > 1 ) trans_map[key] = value.substr(1).substr(0, value.find_last_not_of(" "));
        else throw runtime_error("no rule for "+key);
    }
    return trans_map;
}

const string & transform(const string &s, const map<string, string> &m) {
    auto it = m.find(s);
    return it == m.cend() ? s : it->second;
}

void word_transform(ifstream &map_file, ifstream &input) {
    auto trans_map = buildMap(map_file);
    for (string text; getline(input, text); ) {
        istringstream iss(text);
        bool firstword = true;
        for (string word; iss >> word; ) {
            if (firstword) firstword = false;
            else cout << " ";
            std::cout << transform(word, trans_map);
        }     
        cout << endl;
    }
}

int main () {
    ifstream map_file("../../data/rule_of_transform.txt");
    ifstream input_file("../../data/give_to_transform.txt");
    if (map_file && input_file)
        word_transform(map_file, input_file);
    else 
        std::cerr << "can't find file documents\n";
    return 0;
}
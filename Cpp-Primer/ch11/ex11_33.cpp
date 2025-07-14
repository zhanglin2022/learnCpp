#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <exception>

using std::map; using std::string; using std::cout; using std::endl; 
using std::ifstream; using std::runtime_error; using std::istringstream;

map<string, string> buildMap (ifstream &map_file) {
    map<string, string> trans_map;
    string key, value;
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1 ) trans_map[key] = value.substr(1);
        else throw runtime_error("no rule for "+key);
    }
    return trans_map;
}

string const& transform(const string &s, const map<string, string> &m) {
    auto it = m.find(s);
    return it == m.cend() ? it->second : s;
}

void word_transform(ifstream &map_file, ifstream &input) {
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text)) {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword) firstword = false;
            else cout << " ";
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

int main (int argc, char** argv) {
    if (argc != 3) throw runtime_error("file number not match");
    ifstream map_file(argv[1]), input_file(argv[2]);
    word_transform(map_file, input_file);

    return 0;
}
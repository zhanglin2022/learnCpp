// Exercise 12.28
//
// Write a program to implement text queries without defining classes to 
// manage the data. 
// Your program should take a file and interact with a user to query for 
// words in that file. Use vector, map, and set containers to hold the data 
// for the file and to generate the results for the queries.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>

using std::cin; using std::cout; using std::endl; using std::vector; 
using std::map; using std::set; using std::string; using std::shared_ptr; 
using std::istringstream; using std::ifstream;

using Line_no = vector<string>::size_type;

int main() {
    ifstream file("../../data/give_to_transform.txt");
    vector<string> input;
    map<string, set<Line_no>> word_line;
    Line_no line_no = 0;
    for (string line; getline(file, line); ++line_no) {
        input.push_back(line);
        istringstream line_stream(line);
        for (string text, word; line_stream>>text; word.clear()) {
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            word_line[word].insert(line_no);
        }
    }

    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        string str;
        if (!(std::cin >> str) || str == "q") break;
        auto found = word_line.find(str);
        if (found != word_line.end()) {
            cout << str << " occurs " << found->second.size() << (found->second.size() > 1 ? " times" : " time") << endl;
            for (auto i : found->second)
            cout << "\t(line " << i+1 << ") " << input.at(i) << endl;
        } else cout << str << "occurs 0 time" << endl;
    }
    return 0;
}
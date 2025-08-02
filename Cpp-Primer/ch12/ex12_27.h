#ifndef EX12_27_H
#define EX12_27_H

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
class QueryResult;

class TextQuery { 
public:
    using Line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    // Constructor
    // function query()
    shared_ptr<vector<string>> input; 
    map<string, shared_ptr<set<Line_no>>> word_line;
};

TextQuery::TextQuery(ifstream &ifs): input(new vector<string>) {
    if (!ifs) std::cerr << "No input file" << endl;
    Line_no line_no = 0;
    for (string line; getline(ifs, line); ++line_no) {
        input->push_back(line);
        istringstream line_stream(line);
        for (string text, word; line_stream >> text; word.clear()) {
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            // use reference avoid count of shared_ptr add
            // if word isn’t already in wm, subscripting adds a new entry
            auto &lines = word_line[word];
            // that pointer is null the first time we see word
            if (!lines) lines.reset(new set<Line_no>); 
            lines->insert(line_no);
        }
    }
}












#endif
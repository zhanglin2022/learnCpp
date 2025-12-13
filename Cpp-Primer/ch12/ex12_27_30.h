// Exercise 12.27
//
// The TextQuery and QueryResult classes use only capabilities that we have already 
// covered. Without looking ahead, write your own versions of these classes.
//

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
            // if word isn’t already in word_line, subscripting adds a new entry
            auto &lines = word_line[word];
            // that pointer is null the first time we see word
            if (!lines) lines.reset(new set<Line_no>); 
            lines->insert(line_no);
        }
    }
}

class QueryResult{
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(string s, 
                shared_ptr<set<TextQuery::Line_no>> p,
                shared_ptr<vector<string>> f):
        word(s), lines(p), input(f) { }
private:
    string word;
    shared_ptr<set<TextQuery::Line_no>> lines;
    shared_ptr<vector<string>> input;
};

QueryResult TextQuery::query(const string &str) const {
    // use static just allocate once
    static shared_ptr<set<Line_no>> nodata(new set<Line_no>);
    auto found = word_line.find(str);
    if (found == word_line.end()) return QueryResult(str, nodata, input);
    else return QueryResult(str, found->second, input);
}

std::ostream& print(std::ostream &os, const QueryResult &qr) {
    os << qr.word << " occurs " << qr.lines->size() << (qr.lines->size() > 1 ? " times" : " time") << endl;
    for (auto i : *qr.lines)
        os << "\t(line " << i + 1 << ") " << qr.input->at(i) << endl;
    return os;
}

#endif
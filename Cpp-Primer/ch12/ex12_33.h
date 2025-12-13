// Exercise 12.33
// 
// In Chapter 15 we’ll extend our query system and will need some additional 
// members in the QueryResult class. 
// Add members named begin and end that return iterators into the set of line 
// numbers returned by a given query, and a member named get_file that returns 
// a shared_ptr to the file in the QueryResult object.
//

#ifndef EX12_33_H
#define EX12_33_H

#include "ex12_22.h"
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
    using Line_no = StrBlob::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    StrBlob input;
    map<string, shared_ptr<set<StrBlob::size_type>>> word_line;
};

TextQuery::TextQuery(ifstream &ifs) {
    if (!ifs) std::cerr << "No input file" << endl;
    Line_no line_no = 0;
    for (string line; getline(ifs, line); ++line_no) {
        input.push_back(line);
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
using ResultIter = set<TextQuery::Line_no>::iterator;
public:
    QueryResult(string s, 
                shared_ptr<set<StrBlob::size_type>> p,
                const StrBlob &f):
        word(s), lines(p), input(f) { }
    ResultIter begin() const { return lines->begin(); }
    ResultIter end() const { return lines->end(); }
    shared_ptr<StrBlob> getfile() const { return make_shared<StrBlob>(input); }
private:
    string word;
    shared_ptr<set<TextQuery::Line_no>> lines;
    StrBlob input;
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
    for (auto it = qr.begin(); it != qr.end(); ++it) {
        ConstStrBlobPtr p(*qr.getfile(), *it);
        os << "\t(line " << *it + 1 << ") " << p.deref() << endl;
    }
    return os;
}

#endif
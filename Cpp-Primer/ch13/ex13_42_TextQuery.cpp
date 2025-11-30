// Exercise 13.42
//
// Test your StrVec class by using it in place of the vector<string> 
// in your TextQuery and QueryResult classes
//

#include "ex13_42_TextQuery.h"
#include <sstream>
#include <algorithm>

TextQuery::TextQuery(std::ifstream &ifs): input(new StrVec) {
    if (!ifs) std::cerr << "No input file" << std::endl;
    size_t lineNo = 0;
    for (string line; getline(ifs, line); ++lineNo) {
        input->push_back(line);
        std::istringstream line_stream(line);
        for (string text, word; line_stream >> text; word.clear()) {
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            // use reference avoid count of shared_ptr add
            // if word isn’t already in word_line, subscripting adds a new entry
            auto &lines = word_line[word];
            // that pointer is null the first time we see word
            if (!lines) lines.reset(new std::set<size_t>); 
            lines->insert(lineNo);
        }
    }
}

QueryResult TextQuery::query(const string &str) const {
    // use static just allocate once
    static std::shared_ptr<std::set<size_t>> nodata(new std::set<size_t>);
    auto found = word_line.find(str);
    if (found == word_line.end()) return QueryResult(str, nodata, input);
    else return QueryResult(str, found->second, input);
}

std::ostream& print(std::ostream &os, const QueryResult &qr) {
    os << qr.word << " occurs " << qr.lines->size() << (qr.lines->size() > 1 ? " times" : " time") << std::endl;
    for (auto i : *qr.lines)
        os << "\t(line " << i + 1 << ") " << qr.input->at(i) << std::endl;
    return os;
}

int main() {
    return 0;
}
//
// Exercise 12.32:
// Rewrite the TextQuery and QueryResult classes to use a StrBlob instead of a
// vector<string> to hold the input file.
//  Relevant post on Stack Overflow:
//  http://stackoverflow.com/questions/20823225/what-will-happen-if-a-user-defined-constructor-omits-ininitialization-for-data-m
//

#include "textquery.h"
#include "queryresult.h"
#include <iostream>
#include <sstream>
#include <algorithm>

TextQuery::TextQuery(std::ifstream &fin) : 
   file(StrBlob()), 
   wordMap(std::map<std::string, std::shared_ptr<std::set<line_no>>> ()) {
   if (!fin) throw std::runtime_error("Cannot open file");
    
   for (std::string line; std::getline(fin, line);) {
       file.push_back(line);
       line_no n = file.size() - 1; // the current line number
       std::istringstream iss(line);
       for (std::string text, word; iss >> text; word.clear()) {
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            // use reference avoid count of shared_ptr add
            // if word isn’t already in word_line, subscripting adds a new entry
            if(word.empty()) continue;
            auto &lines = wordMap[word];
            // that pointer is null the first time we see word
            if (!lines) lines.reset(new std::set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &str) const {
    // use static just allocate once
    static std::shared_ptr<std::set<line_no>> noData(new std::set<line_no>);
    auto iter = wordMap.find(str);
    if (iter == wordMap.end()) return QueryResult(str, noData, file);
    else return QueryResult(str, iter->second, file);
}

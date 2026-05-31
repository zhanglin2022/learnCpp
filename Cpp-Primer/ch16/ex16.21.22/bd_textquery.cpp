// Exercise 15.42_b

#include <iostream>
#include <sstream>
#include <algorithm>

#include "bd_textquery.h"
#include "bd_queryresult.h"

TextQuery::TextQuery(std::ifstream &fin) : 
   file(new std::vector<std::string>(), DebugDelete()), 
   wordMap( new std::map<std::string, std::shared_ptr<std::set<size_t>>>(), DebugDelete()) {
   if (!fin) throw std::runtime_error("Cannot open file");
    
   for (std::string line; std::getline(fin, line);) {
       file->push_back(line);
       size_t n = file->size() - 1; // the current line number
       std::istringstream iss(line);
       for (std::string text, word; iss >> text; word.clear()) {
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            // use reference avoid count of shared_ptr add
            // if word isn’t already in word_line, subscripting adds a new entry
            if(word.empty()) continue;
            auto &lines = (*wordMap)[word];
            // that pointer is null the first time we see word
            if (!lines) lines.reset(new std::set<size_t>, DebugDelete());
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &str) const {
    // use static just allocate once
    static std::shared_ptr<std::set<size_t>> noData(new std::set<size_t>, DebugDelete());
    auto iter = wordMap->find(str);
    if (iter == wordMap->end()) return QueryResult(str, noData, file);
    else return QueryResult(str, iter->second, file);
}

// Exercise 13.42
//
// Test your StrVec class by using it in place of the vector<string> 
// in your TextQuery and QueryResult classes
//

#ifndef EX13_42_TEXTQUERY_H
#define EX13_42_TEXTQUERY_H

#include "ex13_42_StrVec.h"

#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <map>
#include <set>

class QueryResult;
class TextQuery { 
public:
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<StrVec> input; 
    std::map<std::string, std::shared_ptr<std::set<size_t>>> word_line;
};

class QueryResult{
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s, 
                std::shared_ptr<std::set<size_t>> p,
                std::shared_ptr<StrVec> f):
        word(s), lines(p), input(f) { }
private:
    std::string word;
    std::shared_ptr<std::set<size_t>> lines;
    std::shared_ptr<StrVec> input;
};

#endif
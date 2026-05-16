//
// Exercise 12.32:
// Rewrite the TextQuery and QueryResult classes to use a StrBlob instead of a
// vector<string> to hold the input file.
//  Relevant post on Stack Overflow:
//  http://stackoverflow.com/questions/20823225/what-will-happen-if-a-user-defined-constructor-omits-ininitialization-for-data-m
//

#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <string>
#include <map>
#include <set>
#include <memory>
#include <fstream>

#include "StrBlob.h"

class QueryResult;

class TextQuery {
public:
    using line_no = StrBlob::size_type;

    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;

private:
    StrBlob file;
    std::map<std::string, std::shared_ptr<std::set<StrBlob::size_type>>> wordMap;
};

#endif // TEXTQUERY_H
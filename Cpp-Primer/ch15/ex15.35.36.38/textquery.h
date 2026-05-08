//
// Exercise 12.32:
// Rewrite the TextQuery and QueryResult classes to use a StrBlob instead of a
// vector<string> to hold the input file.
//  Relevant post on Stack Overflow:
//  http://stackoverflow.com/questions/20823225/what-will-happen-if-a-user-defined-constructor-omits-ininitialization-for-data-m
//

#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include "StrBlob.h"
#include <map>
#include <set>
#include <string>
#include <memory>
#include <fstream>

class QueryResult;

/**
 * @brief The TextQuery class using StrBlob
 */
class TextQuery {
public:
    using line_no = StrBlob::size_type;

    // constructor
    TextQuery(std::ifstream&);

    // query operation
    QueryResult query(const std::string&) const;

private:
    StrBlob file;
    std::map<std::string, std::shared_ptr<std::set<StrBlob::size_type>>> wordMap;
};

#endif
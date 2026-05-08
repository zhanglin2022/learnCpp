//
// Exercise 12.33:
// In Chapter 15 we’ll extend our query system and will need some additional
// members in the QueryResult class.
//
// Add members named begin and end that
// return iterators into the set of line numbers returned by a given query,
// and a member named get_file that returns a shared_ptr to the file in the
// QueryResult object.
//

#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include "textquery.h"
#include <iostream>
#include <string>

/**
 * @brief Query Result
 */
class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    QueryResult(std::string s, 
                std::shared_ptr<std::set<StrBlob::size_type>> p,
                const StrBlob &f):
        word(s), lines(p), file(f) { }
    
    const StrBlob& get_file() const{ return file; }

    std::set<TextQuery::line_no>::iterator begin() { return lines->begin(); }
    std::set<TextQuery::line_no>::iterator end()   { return lines->end(); }

private:
    std::string word;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    StrBlob file;
};

/**
 * @brief print the result to the output stream specified.
 */
std::ostream& print(std::ostream&, const QueryResult&);

#endif

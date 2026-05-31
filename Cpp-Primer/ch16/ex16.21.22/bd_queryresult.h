// Exercise 15.42_b

#ifndef BD_QUERYRESULT_H
#define BD_QUERYRESULT_H

#include "bd_textquery.h"
#include <iostream>
#include <string>

class QueryResult {
friend std::ostream& operator<<(std::ostream&, const QueryResult&);

public:
    QueryResult(std::string s, 
                std::shared_ptr<std::set<size_t>> p,
                const std::shared_ptr<std::vector<std::string>> &f):
        sought(s), lines(p), file(f) { }
    
    std::set<size_t>::iterator begin() { return lines->begin(); }
    std::set<size_t>::iterator end()   { return lines->end(); }
    const std::shared_ptr<std::vector<std::string>>& get_file() const { return file; }

private:
    std::string sought;
    std::shared_ptr<std::set<size_t>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

std::ostream& operator<<(std::ostream&, const QueryResult&);

#endif // BD_QUERYRESULT_H

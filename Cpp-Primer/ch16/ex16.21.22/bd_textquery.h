// Exercise 15.42_b

#ifndef BD_TEXTQUERY_H
#define BD_TEXTQUERY_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <fstream>

#include "DebugDelete.h"

class QueryResult;

class TextQuery {
public:
    TextQuery(std::ifstream&);

    QueryResult query(const std::string&) const;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::map<std::string, std::shared_ptr<std::set<size_t>>>> wordMap;
};

#endif // BD_TEXTQUERY_H
#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string>
#include <memory>
#include "query_base.h"
#include "queryresult.h"
#include "textquery.h"
#include "wordquery.h"

/**
 * @brief interface class to manage the Query_base inheritance hierachy
 */
class Query {
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

public:
    Query(const std::string &s): q(new WordQuery(s)) { }
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { return q->rep(); }

private:
    Query(std::shared_ptr<Query_base> query) : q(query) { }
    std::shared_ptr<Query_base> q;
};

inline std::ostream& operator<< (std::ostream& os, const Query& query) {
    return os << query.rep();
}

#endif // QUERY_H

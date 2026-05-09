#ifndef NOTQUERY_H
#define NOTQUERY_H

#include "query_base.h"
#include "query.h"

/**
 * @brief NotQuery class
 * 
 * The ~operator generator a NotQuery, which hold a Query,
 * which it negates.
 */
class NotQuery: public Query_base {
    friend Query operator~(const Query&);
    NotQuery(const Query &q) : query(q) { 
        std::cout << "NotQuery::NotQuery()\n";
    }

    // virtuals
    QueryResult eval(const TextQuery &t) const override;
    std::string rep() const override {
        std::cout << "NotQuery::rep()\n";
        return "~(" + query.rep() + ")";
    }

    Query query;    
};

inline Query operator~(const Query &operand) {
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

#endif
#ifndef ORQUERY_H
#define ORQUERY_H

#include "binaryquery.h"

class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right): 
        BinaryQuery(left, right, "|") {
        std::cout << "OrQuery::OrQuery()\n";
    }
    // AndQuery inherits rep and defines the remaining pure virtual
    QueryResult eval(const TextQuery &t) const override {
        // this is just a placeholder rather than the real definition
    }
};

inline Query operator|(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif // ORQUERY_H

#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include "query_base.h"
#include "query.h"

class BinaryQuery: public Query_base {
// all private    
    BinaryQuery(const Query &l, const Query &r, std::string s) :
        lhs(l), rhs(r), opSym(s) { }
    std::string rep() const override { return "(" + lhs.rep() + 
                                + " " + opSym + " " 
                                + rhs.rep() + ")";
    }
    Query lhs, rhs;
    std::string opSym;

};

#endif

#ifndef QUERYHISTORY_H
#define QUERYHISTORY_H

#include <vector>

#include "query.h"

class QueryHistory {
public:
    Query& operator[] (size_t n) { return query_vec[n]; }
    const Query& operator[](size_t n) const { return query_vec[n]; }
    size_t add_query(const Query&);

private:
    std::vector<Query> query_vec;
};

#endif
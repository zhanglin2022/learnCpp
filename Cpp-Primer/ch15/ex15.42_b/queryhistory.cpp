#include <memory>

#include "queryhistory.h"

size_t QueryHistory::add_query(const Query &query) {
    query_vec.push_back(query);
    return query_vec.size() - 1;
}
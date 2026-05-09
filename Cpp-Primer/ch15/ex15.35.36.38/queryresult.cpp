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

#include "queryresult.h"

/**
 * @brief   print the result to the output stream specified.
 * @note    class QueryResult's friend
 */
std::ostream& print(std::ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << (qr.lines->size() > 1 ? " times" : " time") << std::endl;
    
    for (auto index : *qr.lines) {
        ConstStrBlobPtr wp(qr.file, index);
        os << "\t(line " << index + 1 << ") " << wp.deref() << std::endl;
    }
    return os;
}

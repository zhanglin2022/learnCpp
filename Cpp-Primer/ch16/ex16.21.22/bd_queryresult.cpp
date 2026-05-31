// Exercise 15.42_b

#include "bd_queryresult.h"

std::ostream& operator<<(std::ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << (qr.lines->size() > 1 ? " times" : " time") << std::endl;
    
    for (auto index : *qr.lines) {
        os << "\t(line " << index + 1 << ") " << (*qr.file)[index] << std::endl;
    }
    return os;
}

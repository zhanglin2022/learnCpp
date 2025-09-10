#ifndef EX13_5_H
#define EX13_5_H

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()): ps(new std::string()), i(0) { }
    HasPtr(const HasPtr& hp): ps(new std::string(*hp.ps)), i(0) {}
private:
    std::string *ps;
    int i;
};

#endif
#ifndef EX13_22_H
#define EX13_22_H

#include <string>
using std::string;

class HasPtr{
public:
    HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
    HasPtr(const HasPtr& hp): ps(new string(*hp.ps)), i(hp.i) {}
    HasPtr& operator=(const HasPtr& hp) {
        string *new_p = new string(*hp.ps);
        delete ps;
        ps = new_p;
        i = hp.i;
        return *this;
    }
    ~HasPtr() { delete ps; }
private:
    string *ps;
    int i;
};

#endif

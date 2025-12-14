// Exercise 12.22
//
// Assume that we want HasPtr to behave like a value. That is, each object should 
// have its own copy of the string to which the objects point. 
// We’ll show the definitions of the copy-control members in the next section. However, 
// you already know everything you need to know to implement these members. 
// Write the HasPtr copy constructor and copy-assignment operator before reading on.
//

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

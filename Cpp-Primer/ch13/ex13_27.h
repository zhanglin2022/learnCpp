// Exercise 13.27
// Define your own reference-counted version of HasPtr.
// @see ex13_22

#ifndef EX13_27_H
#define EX13_27_H

#include <string>
using std::string;

class HasPtr{
public:
    HasPtr(const string &s = string()): ps(new string(s)), i(0), use(new size_t(1)) { }
    HasPtr(const HasPtr &hp): ps(hp.ps), i(hp.i), use(hp.use) { *use++; }
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
private:
    string *ps;
    int i;
    std::size_t *use;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    ++*rhs.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr::~HasPtr() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

#endif
// Exercise13.30
// Write and test a swap function for your valuelike version of HasPtr
// @see ex13_22.h

#ifndef EX13_30_H
#define EX13_30_H

#include <iostream>
#include <string>

using std::string;

class HasPtr{
public:
    friend void swap(HasPtr&, HasPtr&);
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

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
}

#endif

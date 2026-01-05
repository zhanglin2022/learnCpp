//  Exercise 13.31 
//
// Give your class a < operator and define a vector of HasPtrs. Give that
// vector some elements and then sort the vector. Note when swap is called.
//

#ifndef EX13_31_H
#define EX13_31_H

#include <iostream>
#include <string>

using std::string;

class HasPtr{
public:
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr&, const HasPtr&);

    HasPtr(const string &s = string()): ps(new string(s)), i(0) { }
    HasPtr(const HasPtr& hp): ps(new string(*hp.ps)), i(hp.i) { }

    HasPtr& operator=(HasPtr rhs) {
        this->swap(rhs);
        return *this;
    }

    ~HasPtr() { delete ps; }

    void swap(HasPtr& rhs) {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        std::cout << "swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
    }

    void print() const {
        std::cout << *ps << std::endl;
    }

private:
    string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    lhs.swap(rhs);
}

inline bool operator<(const HasPtr& lhs, const HasPtr &rhs) {
    return *lhs.ps < *rhs.ps;
}

#endif
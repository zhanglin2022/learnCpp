// Exercise 13.53
//
// @see ex13_31.h
//
// As a matter of low-level efficiency, the HasPtr assignment operator is 
// not ideal. Explain why. 
// Implement a copy-assignment and move-assignment operator for HasPtr and 
// compare the operations executed in your new move-assignment operator 
// versus the copy-and-swap version.
//

#ifndef EX13_53_H
#define EX13_53_H

#include <string>

using std::string;

class HasPtr{
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const string &s = string());
    HasPtr(const HasPtr &hp);
    HasPtr(HasPtr &&p) noexcept;
    HasPtr& operator=(HasPtr rhs);
    // HasPtr& operator=(const HasPtr &rhs);
    // HasPtr& operator=(HasPtr &&rhs) noexcept;
    ~HasPtr();

private:
    string *ps;
    int i;
};

#endif

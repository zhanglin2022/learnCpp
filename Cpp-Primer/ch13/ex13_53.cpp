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

#include "ex13_53.h"
#include <iostream>

void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "call swap" << std::endl;
}

HasPtr::HasPtr(const string &s): ps(new string(s)), i(0) { 
    std::cout << "call constructor" << std::endl;
}

HasPtr::HasPtr(const HasPtr& hp): ps(new string(*hp.ps)), i(hp.i) { 
    std::cout << "call copy constructor" << std::endl;
}

HasPtr::HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {
    p.ps = nullptr;
    std::cout << "call move constructor" << std::endl;
}

HasPtr& HasPtr::operator=(HasPtr rhs) {
    swap(*this, rhs);
    return *this;
}

// HasPtr& HasPtr::operator=(const HasPtr &rhs) {
//     if (this != &rhs) {
//         auto temp = new string(*rhs.ps);
//         delete ps;
//         ps = temp;
//         i = rhs.i;
//     }
//     std::cout << "call copy-assignment" << std::endl;
//     return *this;
// }

// HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept {
//     if (this != &rhs) {
//         delete ps;
//         ps = rhs.ps;
//         i = rhs.i;
//         rhs.ps = nullptr;
//     }
//     std::cout << "call move-assignment" << std::endl;
//     return *this;
// }

HasPtr::~HasPtr() {
    std::cout << "call destructor" << std::endl;
    delete ps; 
}

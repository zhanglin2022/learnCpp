// Exercise 13.8
//
// Write the assignment operator for the HasPtr class from exercise 13.5 
// in § 13.1.1 (p. 499). 
// As with the copy constructor, your assignment operator should copy the 
// object to which ps points.
//

#ifndef EX13_8_H
#define EX13_8_H

#include <string>
#include <memory>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()): 
        ps(new std::string(s)), i(0) {}
    HasPtr& operator=(const HasPtr &rhs_hp) {
        if (this != &rhs_hp) {
            std::string *temp_ps = new std::string(*rhs_hp.ps);
            delete ps;
            ps = temp_ps;
            i = rhs_hp.i;
        }
        return *this;
    }
private:
    std::string *ps;
    int i;
};

#endif
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
    ~HasPtr() { delete ps; }
private:
    std::string *ps;
    int i;
};

#endif
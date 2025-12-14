// Exercise 13.5
//
// Given the following sketch of a class, write a copy constructor that copies 
// all the members. 
// Your constructor should dynamically allocate a new string (§ 12.1.2, p. 458) 
// and copy the object to which ps points, rather than copying ps itself. 
// 
// class HasPtr { 
// public: 
//  HasPtr(const std::string &s = std::string()): 
//      ps(new std::string(s)), i(0) { } 
// private: 
//     std::string *ps; 
//     int i; 
// };
//

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
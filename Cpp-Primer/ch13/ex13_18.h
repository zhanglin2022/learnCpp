// Exercise 13.18
// 
// Define an Employee class that contains an employee name and a unique employee 
// identifier. Give the class a default constructor and a constructor that takes 
// a string representing the employee’s name. 
// Each constructor should generate a unique ID by incrementing a static data member.
//

#ifndef EX13_18_H
#define EX13_18_H

#include <string>

using std::string;

class Employee {
public:
    Employee() { id_ = s_increment++; }
    Employee(string &name) { name_ = name; id_ = s_increment++; }

    const int id() const {return id_; }

private:
    string name_;
    int id_;
    static int s_increment;
};

#endif

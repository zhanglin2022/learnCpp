// Exercise 13.19
// 
// Does your Employee class need to define its own versions of the copy-control 
// members? If so, why? If not, why not? Implement whatever copy-control members 
// you think Employee needs.
//

#ifndef EX13_19_H
#define EX13_19_H

#include <string>

using std::string;

class Employee {
public:
    Employee() { id_ = s_increment++; }
    Employee(string &name) { name_ = name; id_ = s_increment++; }
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;

    const int id() const {return id_; }

private:
    string name_;
    int id_;
    static int s_increment;
};

#endif

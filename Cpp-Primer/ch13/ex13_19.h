#ifndef EX13_8_H
#define EX13_8_H

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

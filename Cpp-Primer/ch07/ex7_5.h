#ifndef EX7_5_H
#define EX7_5_H

#include <string>

using std::string;

struct Person {
    string name;
    string address;

    string const& getName() const { return name; }
    string const& getAddress() const { return address; }
};

#endif
#ifndef EX7_9_H
#define EX7_9_H

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;

struct Person {
    string name;
    string address;

    const string & getName() const { return name; }
    const string & getAddress() const { return address; }
};

istream &read (istream &is, Person &person) {
    return is >> person.name >> person.address;   
}

ostream &print (ostream &os, const Person &person) {
    return os << person.name << " " << person.address;
}

#endif
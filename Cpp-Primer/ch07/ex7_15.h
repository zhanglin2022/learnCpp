#ifndef EX7_15_H
#define EX7_15_H

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;

struct Person;
istream &read (istream& is, Person&);

struct Person {
    Person() = default;
    Person(const string& sname, const string& saddr): name(sname), address(saddr) {}
    Person(istream& is) { read(is, *this); }

    const string & getName() const { return name; }
    const string & getAddress() const { return address; }
    
    string name;
    string address;
};

istream &read (istream &is, Person &person) {
    return is >> person.name >> person.address;   
}

ostream &print (ostream &os, const Person &person) {
    return os << person.name << " " << person.address;
}

#endif
#ifndef EX7_50_H
#define EX7_50_H

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;

class Person {
friend istream &read (istream &is, Person &person);
friend ostream &print (ostream &os, const Person &person);

public:
    Person() = default;
    Person(const string& sname, const string& saddr): name(sname), address(saddr) {}
    explicit Person(istream& is) { read(is, *this); }

    const string & getName() const { return name; }
    const string & getAddress() const { return address; }
private:    
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
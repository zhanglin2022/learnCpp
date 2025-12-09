// Exercise 7.5
//
// Provide operations in your Person class to return the name and address. 
// Should these functions be const? Explain your choice.
//

#ifndef EX7_5_H
#define EX7_5_H

#include <string>

using std::string;

struct Person {
    string name;
    string address;

    const string & getName() const { return name; }
    const string & getAddress() const { return address; }
};

#endif
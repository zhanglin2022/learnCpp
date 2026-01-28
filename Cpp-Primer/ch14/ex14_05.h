// Exercise 14.5
//
// @See Exercise 7.40
//
// Decide what, if any, overloaded operators Book class should provide.
//

#ifndef EX14_05_H
#define EX14_05_H

#include <iostream>
#include <string>

class Book {
    friend std::istream& operator>>(std::istream&, Book&);
    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);

public:
    Book() = default;
    Book(unsigned isbn, std::string const& name, std::string const& author, std::string const& pubdate) :isbn_(isbn), name_(name), author_(author), pubdate_(pubdate) { }
    Book(std::istream &in) { in >> *this; }

private:
    unsigned isbn_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
};

std::istream& operator>>(std::istream&, Book&);
std::ostream& operator<<(std::ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);

#endif
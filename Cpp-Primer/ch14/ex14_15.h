// Exercise 14.15
//
// @See Exercise 14.5
//
// Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define any of 
// the arithmetic operators? 
// If so, implement them. If not, explain why not.
//

#ifndef EX14_15_H
#define EX14_15_H

#include <iostream>
#include <string>

class Book {
    friend std::istream& operator>>(std::istream&, Book&);
    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);
    friend bool operator>(const Book&, const Book&);
    friend bool operator<(const Book&, const Book&);
    friend Book operator+(const Book&, const Book&);

public:
    Book() = default;
    Book(unsigned no, std::string const& name, std::string const& author, std::string const& pubdate, unsigned number) :
        no_(no), name_(name), author_(author), pubdate_(pubdate), number_(number) { }
    Book(std::istream &in) { in >> *this; }

    Book& operator+=(const Book&);

private:
    unsigned no_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
    unsigned number_;
};

std::istream& operator>>(std::istream&, Book&);
std::ostream& operator<<(std::ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);
bool operator>(const Book&, const Book&);
bool operator<(const Book&, const Book&);
Book operator+(const Book&, const Book&);

#endif



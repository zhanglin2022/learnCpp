// Exercise 14.49
//
// @See Exercise 14.25
//
// Regardless of whether it is a good idea to do so, define a 
// conversion to bool for the class from the previous exercise.
//

#ifndef EX14_49_H
#define EX14_49_H

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
    Book(unsigned no) : no_(no) { } 

    Book& operator=(const unsigned);
    Book& operator+=(const Book&);
    explicit operator bool() { return no_ != 0; }

private:
    unsigned no_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
    unsigned number_ = 0;
};

std::istream& operator>>(std::istream&, Book&);
std::ostream& operator<<(std::ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);
bool operator>(const Book&, const Book&);
bool operator<(const Book&, const Book&);
Book operator+(const Book&, const Book&);

#endif


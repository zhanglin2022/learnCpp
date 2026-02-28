// Exercise 14.25
//
// @See Exercise 14.15
//
// Implement any other assignment operators your class should define. 
// Explain which types should be used as operands and why.

#include "ex14_25.h"

Book& Book::operator=(const unsigned isbn) {
    *this = Book(isbn);
    return *this;
}

Book& Book::operator+=(const Book &rhs) {
    if (*this == rhs)
        number_ += rhs.number_;
    return *this;
}

std::istream& operator>>(std::istream &is, Book &book) {
    is >> book.no_ >> book.name_ >> book.author_ >> book.pubdate_ >> book.number_;
    return is;
}

std::ostream& operator<<(std::ostream &os, const Book &book) {
    os << book.no_ << " " << book.name_ << " " << book.author_ << " " << book.pubdate_ << " " << book.number_;
    return os;
}

bool operator==(const Book &lhs, const Book &rhs) {
    return lhs.no_ == rhs.no_;
}

bool operator!=(const Book &lhs, const Book &rhs) {
    return !(lhs == rhs);
}

bool operator>(const Book &lhs, const Book &rhs) {
    return lhs.no_ > rhs.no_;
}

bool operator<(const Book &lhs, const Book &rhs) {
    return rhs > lhs;
}

Book operator+(const Book &lhs, const Book &rhs) {
    Book sum = lhs;
    sum += rhs;
    return sum;
}

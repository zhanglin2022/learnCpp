// Exercise 14.15
//
// @See Exercise 14.5
//
// Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define any of 
// the arithmetic operators? 
// If so, implement them. If not, explain why not.
//

#include "ex14_15.h"

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

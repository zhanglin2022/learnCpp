// Exercise 14.5
//
// @See Exercise 7.40
//
// Decide what, if any, overloaded operators Book class should provide.
//

#include "ex14_05.h"

std::istream& operator>>(std::istream &is, Book &book) {
    is >> book.isbn_ >> book.name_ >> book.author_ >> book.pubdate_;
    return is;
}

std::ostream& operator<<(std::ostream &os, const Book &book) {
    os << book.isbn_ << " " << book.name_ << " " << book.author_ << " " << book.pubdate_;
    return os;
}

bool operator==(const Book &lhs, const Book &rhs) {
    return lhs.isbn_ == rhs.isbn_;
}

bool operator!=(const Book &lhs, const Book &rhs) {
    return !(lhs == rhs);
}

// Exercise 14.26
//
// @See Exercise 14.18 String
//
// Define subscript operators for your StrVec, String, StrBlob, 
// and StrBlobPtr classes.

#include "ex14_26_String.h"
#include <algorithm>

std::allocator<char> String::alloc;

std::ostream& operator<<(std::ostream &os, const String &str) {
    for (auto i = str.begin(); i != str.end(); ++i) 
        os << *i ;
    return os;
}

bool operator==(const String &lhs, const String &rhs) {
    if (lhs.size() != rhs.size())
        return false;
    else {
        for (auto l_iter = lhs.begin(), r_iter = rhs.begin(); l_iter != lhs.end(); ++l_iter, ++r_iter) {
            if (*l_iter != *r_iter)
                return false;
        }
    }
    return true;
}

bool operator!=(const String &lhs, const String &rhs) {
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const String &lhs, const String &rhs) {
    return rhs < lhs;
}

bool operator<=(const String &lhs, const String &rhs) {
    return !(lhs > rhs);
}

bool operator>=(const String &lhs, const String &rhs) {
    return !(lhs < rhs);
}

std::pair<char*, char*> 
String::alloc_n_copy(const char* b, const char *e) {
    auto data = alloc.allocate(e - b);
    return { data, std::uninitialized_copy(b, e, data) };
}

void String::range_initialize(const char *first, const char *last) {
    auto newdata = alloc_n_copy(first, last);
    elements_ = newdata.first;
    end_ = newdata.second;
}

String::String(const char *c) {
    const char *p = c;
    while (*p != '\0')
        ++p;
    range_initialize(c, ++p);
}

void String::free() {
    if (elements_) {
        std::for_each(elements_, end_, [this] (char &c) { alloc.destroy(&c); });
        alloc.deallocate(elements_, end_ - elements_);
    }
}


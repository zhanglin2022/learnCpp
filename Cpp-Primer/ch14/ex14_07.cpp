// Exercise 14.7
//
// @See Ex13_44.cpp
//
// Define an output operator for you String class you wrote for the exercises 
// in § 13.5 (p. 531).
//

#include "ex14_07.h"
#include <algorithm>

std::allocator<char> String::alloc;

std::ostream& operator<<(std::ostream &os, const String &str) {
    for (auto i = str.elements; i != str.end; ++i) 
        os << *i ;
    return os;
}

std::pair<char*, char*> 
String::alloc_n_copy(const char* b, const char *e) {
    auto data = alloc.allocate(e - b);
    return { data, std::uninitialized_copy(b, e, data) };
}

void String::range_initialize(const char *first, const char *last) {
    auto newdata = alloc_n_copy(first, last);
    elements = newdata.first;
    end = newdata.second;
}

String::String(const char *c) {
    const char *p = c;
    while (*p != '\0')
        ++p;
    range_initialize(c, ++p);
}

void String::free() {
    if (elements) {
        std::for_each(elements, end, [this] (char &c) { alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }
}

// Exercise 13.44
// 
// Write a class named String that is a simplified version of the library string class. Your 
// class should have at least a default constructor and a constructor that takes a pointer 
// to a C-style string. Use an allocator to allocate memory that your String class uses.
//

#include "ex13_44.h"
#include <algorithm>

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
    char *str = const_cast<char*>(c);
    while (str)
        ++str;
    range_initialize(c, ++str);
}

void String::free() {
    if (elements) {
        std::for_each(elements, end, [this] (char &c) { alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }
}

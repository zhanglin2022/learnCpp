// Exercise 13.47
// 
// Give the copy constructor and copy-assignment operator in your String 
// class from exercise 13.44 in § 13.5 (p. 531) a statement that prints a 
// message each time the function is executed 
//

#include "ex13_47.h"
#include <iostream>
#include <algorithm>

std::allocator<char> String::alloc;

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
    std::cout << "C-style string" << std::endl;
}

String::String(const String &rhs) {
    range_initialize(rhs.elements, rhs.end);
    std::cout << "copy constructor" << std::endl;
}

void String::free() {
    if (elements) {
        std::for_each(elements, end, [this] (char &c) { alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }
}

String& String::operator=(const String &rhs) {
    auto newstr = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newstr.first;
    end = newstr.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;
}

// Exercise 13.50
//
// @see ex13.49_String.cpp
//
// Put print statements in the move operations in your String class and
// rerun the program from exercise 13.48 in § 13.6.1 (p. 534) that used 
// a vector<String> to see when the copies are avoided.
//

#include "ex13_50_String.h"
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

String::String(String &&s) noexcept : elements(s.elements), end(s.end) {
    std::cout << "String move constructor called" << std::endl;
    s.elements = s.end = nullptr;
}

String& String::operator=(String &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        end = rhs.end;
        rhs.elements = rhs.end = nullptr;
    }
    std::cout << "String move assignment called" << std::endl;
    return *this;
}

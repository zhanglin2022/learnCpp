// Exercise 14.7
//
// @See Ex13_44.h
//
// Define an output operator for you String class you wrote for the exercises 
// in § 13.5 (p. 531).
//

#ifndef EX14_07_H
#define EX14_07_H

#include <memory>
#include <iostream>

class String {
    friend std::ostream& operator<<(std::ostream&, const String&);
public:
    String(): String("") { } // Delegating Constructor
    String(const char*);

    const char* c_str() const { return elements; }
    size_t size() const { return end - elements; }
    size_t length() const { return end - elements + 1; }

private:
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initialize(const char*, const char*);
    void free();

private:
    char *elements;
    char *end;
    static std::allocator<char> alloc;
};

std::ostream& operator<<(std::ostream&, const String&);

#endif
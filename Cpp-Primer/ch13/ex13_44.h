// Exercise 13.44
// 
// Write a class named String that is a simplified version of the library string class. Your 
// class should have at least a default constructor and a constructor that takes a pointer 
// to a C-style string. Use an allocator to allocate memory that your String class uses.
// 

#ifndef EX13_44_H
#define EX13_44_H

#include <memory>

class String {
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

#endif
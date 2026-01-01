// Exercise 13.49
//
// @see ex13_47.h
//
// Add a move constructor and move-assignment operator to your StrVec, 
// String, and Message classes.
// 

#ifndef EX13_49_STRING_H
#define EX13_49_STRING_H

#include <memory>

class String {
public:
    String(): String("") { } // Delegating Constructor
    String(const char*);
    String(const String&);
    String& operator=(const String&);
    String(String&&) noexcept;
    String& operator=(String&&) noexcept;

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
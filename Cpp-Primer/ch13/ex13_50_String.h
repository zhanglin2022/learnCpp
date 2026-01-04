// Exercise 13.50
//
// @see ex13.49_String.h
//
// Put print statements in the move operations in your String class and
// rerun the program from exercise 13.48 in § 13.6.1 (p. 534) that used 
// a vector<String> to see when the copies are avoided.
//

#ifndef EX13_50_STRING_H
#define EX13_50_STRING_H

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
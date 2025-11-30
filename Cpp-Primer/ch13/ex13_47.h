// Exercise 13.47
// 
// Give the copy constructor and copy-assignment operator in your String 
// class from exercise 13.44 in § 13.5 (p. 531) a statement that prints a 
// message each time the function is executed 
//

#ifndef EX13_47_H
#define EX13_47_H

#include <memory>

class String {
public:
    String(): String("") { } // Delegating Constructor
    String(const char*);
    String(const String&);
    String& operator=(const String&);

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

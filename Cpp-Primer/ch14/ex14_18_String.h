// Exercise 14.18
// 
// @See Exercise 14.16
//
// Define relational operators for your StrBlob, StrBlobPtr, StrVec, and 
// String classes.
//

#ifndef EX14_18_STRING_H
#define EX14_18_STRING_H

#include <memory>
#include <iostream>

class String {
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend bool operator==(const String&, const String&);
    friend bool operator!=(const String&, const String&);
    friend bool operator<(const String&, const String&);
    friend bool operator>(const String&, const String&);
    friend bool operator<=(const String&, const String&);
    friend bool operator>=(const String&, const String&);

public:
    String(): String("") { } // Delegating Constructor
    String(const char*);

    const char* c_str() const { return elements_; }
    size_t size() const { return end_ - elements_; }
    size_t length() const { return end_ - elements_ + 1; }
    const char* begin() const { return elements_; }
    const char* end() const { return end_; }

private:
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initialize(const char*, const char*);
    void free();

private:
    char *elements_;
    char *end_;
    static std::allocator<char> alloc;
};

std::ostream& operator<<(std::ostream&, const String&);
bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);
bool operator<(const String&, const String&);
bool operator>(const String&, const String&);
bool operator<=(const String&, const String&);
bool operator>=(const String&, const String&);

#endif

// Exercise 13.42
//
// Test your StrVec class by using it in place of the vector<string> 
// in your TextQuery and QueryResult classes
//

#ifndef EX13_42_STRVEC_H
#define EX13_42_STRVEC_H

#include <string>
#include <memory>
#include <initializer_list>

using std::string; using std::initializer_list;

class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(initializer_list<string>);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    void push_back(const string&); // copy the element
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string* begin() const { return elements; }
    string* end() const { return first_free; }
    
    std::string& at(size_t pos) { return *(elements + pos); }
    const std::string& at(size_t pos) const { return *(elements + pos); }

    void reserve(size_t);
    void resize(size_t);
    void resize(size_t, const string&);

private:
    // utilities used by the copy constructor, assignment operator, and destructor
    std::pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void chk_n_alloc() { if(size() == capacity()) reallocate(); }
    void reallocate();
    void alloc_n_move(size_t new_cap);
    void range_initialize(const string *, const string *);

    string *elements;
    string *first_free;
    string *cap;
    static std::allocator<string> alloc;
};

#endif
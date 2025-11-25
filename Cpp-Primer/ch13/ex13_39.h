// Exercise 13.39
//
// Write your own version of StrVec, including versions of reserve, 
// capacity (§ 9.4, p. 356), and resize (§ 9.3.5, p. 352).
//

#ifndef EX13_39_H
#define EX13_39_H

#include <string>
#include <memory>

using std::string;

class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    void push_back(const string&); // copy the element
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string* begin() const { return elements; }
    string* end() const { return first_free; }
    
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

    string *elements;
    string *first_free;
    string *cap;
    static std::allocator<string> alloc;
};

#endif
// Exercise 14.26

#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <memory>
#include <initializer_list>

using std::string; using std::initializer_list;

class StrVec {
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
    friend bool operator>(const StrVec&, const StrVec&);
    friend bool operator<=(const StrVec&, const StrVec&);
    friend bool operator>=(const StrVec&, const StrVec&);

public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(initializer_list<string>);
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    StrVec(StrVec&&) noexcept;
    StrVec& operator=(StrVec&&) noexcept;
    ~StrVec();

    StrVec& operator=(initializer_list<string>);
    
    void push_back(const string&); // copy the element
    
    template <typename... Args>
    void emplace_back(Args&&...);

    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    string* begin() const { return elements; }
    string* end() const { return first_free; }
    
    std::string& at(size_t pos) { return *(elements + pos); }
    const std::string& at(size_t pos) const { return *(elements + pos); }

    string& operator[](size_t n) { return elements[n]; }
    const string& operator[](size_t n) const { return elements[n]; }

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

bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);
bool operator<(const StrVec&, const StrVec&);
bool operator>(const StrVec&, const StrVec&);
bool operator<=(const StrVec&, const StrVec&);
bool operator>=(const StrVec&, const StrVec&);

#endif // STRVEC_H

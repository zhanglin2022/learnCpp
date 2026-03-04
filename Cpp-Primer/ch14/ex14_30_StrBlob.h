// Exercise 14.30
// 
// @See Exercise 14.27
// 
// Add dereference and arrow operators to your StrBlobPtr class and to the 
// ConstStrBlobPtr class that you defined in exercise 12.22 from § 12.1.6 (p. 476). 
// Note that the operators in constStrBlobPtr must return const references 
// because the data member in constStrBlobPtr points to a const vector.
//

#ifndef EX14_30_H
#define EX14_30_H

#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>

class StrBlobPtr;
class ConstStrBlobPtr;

// class StrBlob

class StrBlob {
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob&, const StrBlob&);
    friend bool operator<(const StrBlob&, const StrBlob&);
    friend bool operator>(const StrBlob&, const StrBlob&);
    friend bool operator<=(const StrBlob&, const StrBlob&);
    friend bool operator>=(const StrBlob&, const StrBlob&);

public:
    using size_type = std::vector<std::string>::size_type;

    StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) {}

    StrBlob(const StrBlob &sb) : data(std::make_shared<std::vector<std::string>>(*sb.data)) { }
    StrBlob& operator=(const StrBlob&);

    StrBlob(const StrBlob &&rhs)  noexcept : data(std::move(rhs.data)) { }
    StrBlob& operator=(StrBlob&&) noexcept;

    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr cbegin() const;
    ConstStrBlobPtr cend() const;

    std::string& operator[](size_t n);
    const std::string& operator[](size_t n) const;
    
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    std::string& front();
    std::string& back();
    const std::string& front() const;
    const std::string& back() const;

private:
    void check(size_type i, const std::string &msg) const;

private:
    std::shared_ptr<std::vector<std::string>> data;
};

bool operator==(const StrBlob&, const StrBlob&);
bool operator!=(const StrBlob&, const StrBlob&);
bool operator<(const StrBlob&, const StrBlob&);
bool operator>(const StrBlob&, const StrBlob&);
bool operator<=(const StrBlob&, const StrBlob&);
bool operator>=(const StrBlob&, const StrBlob&);

// class StrBlobPtr

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    
    bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }

    std::string& operator*() const;
    std::string* operator->() const;

    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    StrBlobPtr& operator+=(size_t);
    StrBlobPtr& operator-=(size_t);
    StrBlobPtr operator+(size_t);
    StrBlobPtr operator-(size_t);

    std::string& operator[](size_t n);
    const std::string& operator[](size_t) const;


private:
    std::shared_ptr<std::vector<std::string>> 
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
bool operator<(const StrBlobPtr&, const StrBlobPtr&);
bool operator>(const StrBlobPtr&, const StrBlobPtr&);
bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
bool operator>=(const StrBlobPtr&, const StrBlobPtr&);

// class ConstStrBlobPtr

class ConstStrBlobPtr {
    friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
public:
    ConstStrBlobPtr(): curr(0) { }
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    
    bool operator!=(const ConstStrBlobPtr &p) { return p.curr != curr; }

    const std::string& operator*() const;
    const std::string* operator->() const;

    ConstStrBlobPtr& operator++();
    ConstStrBlobPtr& operator--();
    ConstStrBlobPtr operator++(int);
    ConstStrBlobPtr operator--(int);
    ConstStrBlobPtr& operator+=(size_t);
    ConstStrBlobPtr& operator-=(size_t);
    ConstStrBlobPtr operator+(size_t);
    ConstStrBlobPtr operator-(size_t);
    
    const std::string& operator[](size_t n) const;

private:
    std::shared_ptr<std::vector<std::string>> 
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

#endif

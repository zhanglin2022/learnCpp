// Exercise 13.26
// Write your own version of StrBlob described in the previous exercise
// @see ex12_22 and ex13_25

#ifndef EX13_26_H
#define EX13_26_H

#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>

using std::vector; using std::string; using std::make_shared; using std::weak_ptr;

// forward declaration needed for friend declaration in StrBlob
class ConstStrBlobPtr;

class StrBlob {
    friend class ConstStrBlobPtr;
public:
    using size_type = vector<string>::size_type;

    StrBlob(): data(make_shared<vector<string>>()) { }
    StrBlob(std::initializer_list<string> il): data(make_shared<vector<string>>(il)) { }
    // copy constructor
    StrBlob(const StrBlob& sb): data(std::make_shared<vector<string>>(*sb.data)) { }
    // copy assignment
    StrBlob& operator=(const StrBlob &sb);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &t) { data->push_back(t); }
    void pop_back();

    string& front();
    string& back();
    const string& front() const;
    const string& back() const;

    ConstStrBlobPtr begin() const; // should add const
    ConstStrBlobPtr end() const; // should add const

private:
    void check(size_type i, const string &msg) const;

private:
    std::shared_ptr<vector<string>> data;
};

StrBlob& StrBlob::operator=(const StrBlob &sb) {
    data = std::make_shared<vector<string>>(*sb.data);
    return *this;
}

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size()) throw std::out_of_range(msg);
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

string& StrBlob::front() { 
    check(0, "front on empty StrBlob"); 
    return data->front(); 
} 

string& StrBlob::back() { 
    check(0, "back on empty StrBlob"); 
    return data->back(); 
}

const string& StrBlob::front() const {
    check(0, "front on empty StrBlob"); 
    return data->front();
}

const string& StrBlob::back() const {
    check(0, "back on empty StrBlob"); 
    return data->back(); 
}

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr(): curr(0) { }
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0):
            wptr(a.data), curr(sz) { } // should add const
    bool operator!=(const ConstStrBlobPtr &p) { return p.curr != curr; }
    const string& deref() const; // return value should add const
    ConstStrBlobPtr& incr();

private:
    std::shared_ptr<vector<string>> 
        check(std::size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    std::size_t curr;
};

std::shared_ptr<vector<string>>
ConstStrBlobPtr::check(std::size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret) throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size()) throw std::runtime_error(msg);
    return ret;
}

const string& ConstStrBlobPtr::deref() const {  // should add const
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr() {
    auto p = check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

ConstStrBlobPtr StrBlob::begin() const {  // should add const
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const {    // should add const
    return ConstStrBlobPtr(*this, data->size());
}

#endif

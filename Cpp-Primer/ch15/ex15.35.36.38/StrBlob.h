/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * 
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced. Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/

#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

// forward declaration needed for friend declaration in StrBlob
class StrBlobPtr;
// forward declaration needed for friend declaration in StrBlob
class ConstStrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

public:
    using size_type = std::vector<std::string>::size_type;

	// constructors
    StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) {}
	
    // size operations
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // add and remove elements
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
   
    // element access
    std::string& front();
    std::string& back();
    const std::string& front() const;
    const std::string& back() const;

	// interface to StrBlobPtr
    StrBlobPtr begin(); // can't be defined until StrBlobPtr is
    StrBlobPtr end();

    ConstStrBlobPtr begin() const; // should add const
    ConstStrBlobPtr end() const; // should add const

private:
    std::shared_ptr<std::vector<std::string>> data;
    // throws msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};

void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) throw std::out_of_range(msg);
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string& StrBlob::front() { 
    check(0, "front on empty StrBlob"); 
    return data->front(); 
} 

std::string& StrBlob::back() { 
    check(0, "back on empty StrBlob"); 
    return data->back(); 
}

const std::string& StrBlob::front() const {
    check(0, "front on empty StrBlob"); 
    return data->front();
}

const std::string& StrBlob::back() const {
    check(0, "back on empty StrBlob"); 
    return data->back(); 
}

class StrBlobPtr {
    friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
        
    std::string& deref() const;
    StrBlobPtr& incr();  // prefix version
    StrBlobPtr& decr();  // prefix version
private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<std::string>> 
        check(std::size_t, const std::string&) const;
    
    // store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

inline std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size()) throw std::runtime_error(msg);
    return ret;
}

inline std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

inline StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr& StrBlobPtr::decr() {
    // if curr is zero, decrementing it will yield an invalid subscript
    if (curr == 0)
        throw std::out_of_range("decrement past begin of StrBlobPtr");
    --curr;
    return *this;
}


StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	// if the underlying vector is the same 
	if (l == r) 
		// then they're equal if they're both null or 
		// if they point to the same element
		return (!r || lhs.curr == rhs.curr);
	else
		return false; // if they point to difference vectors, they're not equal
}

inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !eq(lhs, rhs); 
}

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr(): curr(0) { }
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0):
            wptr(a.data), curr(sz) { } // should add const
    bool operator!=(const ConstStrBlobPtr &p) { return p.curr != curr; }
    const std::string& deref() const; // return value should add const
    ConstStrBlobPtr& incr();

private:
    std::shared_ptr<std::vector<std::string>> 
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size()) throw std::runtime_error(msg);
    return ret;
}

const std::string& ConstStrBlobPtr::deref() const {  // should add const
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

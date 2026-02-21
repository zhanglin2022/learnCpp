// Exercise 14.18
// 
// @See Exercise 14.16
//
// Define relational operators for your StrBlob, StrBlobPtr, StrVec, and 
// String classes.
//

#include "ex14_18_StrBlob.h"
#include <algorithm>

// operator of StrBlob

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
    return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(), rhs.data->begin(), rhs.data->end());
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
    return rhs < lhs;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs > rhs);
} 
bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs < rhs);
}

// operator of StrBlobPtr

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return rhs < lhs;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs > rhs);
} 
bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs < rhs);
}

// operator of ConstStrBlobPtr

bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
    return lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
    return !(lhs == rhs);
}

bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
    return lhs.curr < rhs.curr;
}

bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
    return rhs < rhs;
}

bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
    return !(lhs > rhs);
} 
bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs) {
    return !(lhs < rhs);
}

// StrBlob

StrBlob& StrBlob::operator=(const StrBlob &rhs) {
    data = std::make_shared<std::vector<std::string>>(*rhs.data);
    return *this;
}

StrBlob& StrBlob::operator=(StrBlob &&rhs) noexcept {
    if (this != &rhs) {
        data = std::move(rhs.data);
        rhs.data = nullptr;
    }
    return *this;
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::cbegin() const {  // should add const
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const {    // should add const
    return ConstStrBlobPtr(*this, data->size());
}

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

// StrBlobPtr

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size()) throw std::runtime_error(msg);
    return ret;
}

std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    auto p = check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

// ConstStrBlobPtr

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

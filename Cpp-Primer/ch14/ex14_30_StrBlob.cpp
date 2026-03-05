// Exercise 14.30
// 
// @See Exercise 14.27
// 
// Add dereference and arrow operators to your StrBlobPtr class and to the 
// ConstStrBlobPtr class that you defined in exercise 12.22 from § 12.1.6 (p. 476). 
// Note that the operators in constStrBlobPtr must return const references 
// because the data member in constStrBlobPtr points to a const vector.
//

#include "ex14_30_StrBlob.h"
#include <algorithm>

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

std::string& StrBlob::operator[](size_t n) {
    check(n, "out of range");
    return data->at(n);
}

const std::string& StrBlob::operator[](size_t n) const {
    check(n, "out of range");
    return data->at(n);
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

std::string& StrBlobPtr::operator*() const {
    return deref();
}

std::string* StrBlobPtr::operator->() const {
    return & this->operator*();
}

StrBlobPtr& StrBlobPtr::operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--() {
    check(--curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int) {
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr& StrBlobPtr::operator+=(size_t n)
{
    size_t new_curr = curr + n;
    check(new_curr, "increment past end of StrBlobPtr");
    curr = new_curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator-=(size_t n)
{
    size_t new_curr = curr - n;
    check(new_curr, "increment past begin of StrBlobPtr");
    curr = new_curr;
    return *this;
}

StrBlobPtr StrBlobPtr::operator+(size_t n) {
    StrBlobPtr ret = *this;
    ret += n;
    return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t n) {
    StrBlobPtr ret = *this;
    ret += n;
    return ret;
}

std::string& StrBlobPtr::operator[](size_t n) {
    auto p = check(n, "deference out of range");
    return (*p)[n];
}

const std::string& StrBlobPtr::operator[](size_t n) const {
    auto p = check(n, "deference out of range");
    return (*p)[n];
}

// ConstStrBlobPtr

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size()) throw std::runtime_error(msg);
    return ret;
}

const std::string& ConstStrBlobPtr::deref() const {
    auto p = check(curr, "deference past endl");
    return (*p)[curr];
}

const std::string& ConstStrBlobPtr::operator*() const {
    return deref();
}

const std::string* ConstStrBlobPtr::operator->() const {
    return & this->operator*();
}

ConstStrBlobPtr& ConstStrBlobPtr::operator++() {
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}

ConstStrBlobPtr& ConstStrBlobPtr::operator--() {
    check(--curr, "decrement past begin of ConstStrBlobPtr");
    return *this;
}

ConstStrBlobPtr ConstStrBlobPtr::operator++(int) {
    ConstStrBlobPtr ret = *this;
    ++*this;
    return ret;
}

ConstStrBlobPtr ConstStrBlobPtr::operator--(int) {
    ConstStrBlobPtr ret = *this;
    --*this;
    return ret;
}

ConstStrBlobPtr& ConstStrBlobPtr::operator+=(size_t n) {
    size_t new_curr = curr + n;
    check(new_curr, "increment past end of ConstStrBlonPtr");
    curr = new_curr;
    return *this;
}

ConstStrBlobPtr& ConstStrBlobPtr::operator-=(size_t n) {
    size_t new_curr = curr - n;
    check(new_curr, "decrement past begin of ConstStrBlobPtr");
    curr = new_curr;
    return *this;
}

ConstStrBlobPtr ConstStrBlobPtr::operator+(size_t n) {
    ConstStrBlobPtr ret = *this;
    ret += n;
    return ret;
}

ConstStrBlobPtr ConstStrBlobPtr::operator-(size_t n) {
    ConstStrBlobPtr ret = *this;
    ret -= n;
    return ret;
}

const std::string& ConstStrBlobPtr::operator[](size_t n) const {
    auto p = check(n, "dereference out of range");
    return (*p)[n];
}

// friend operator of StrBlob

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

// friend operator of StrBlobPtr

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

// friend operator of ConstStrBlobPtr

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

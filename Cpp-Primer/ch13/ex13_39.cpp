// Exercise 13.39
//
// Write your own version of StrVec, including versions of reserve, 
// capacity (§ 9.4, p. 356), and resize (§ 9.3.5, p. 352).
//

#include "ex13_39.h"

using std::string;

void StrVec::push_back(const string &str) {
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

std::pair<string*, string*> 
StrVec::alloc_n_copy(const string *b, const string *e) {
    // allocate space to hold as many elements as are in the range
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &rhs) {
    auto newdata = alloc_n_copy(rhs.elements, rhs.first_free);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() {
    free();
}

StrVec& StrVec::operator=(const StrVec &rhs) {
    auto newdata = alloc_n_copy(rhs.elements, rhs.first_free);
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

void StrVec::alloc_n_move(size_t new_cap) {
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (auto i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    alloc_n_move(newcapacity);
}

void StrVec::reserve(size_t new_cap) {
    if (new_cap <= size()) return;
    alloc_n_move(new_cap);
}

void StrVec::resize(size_t count, const string &s) {
    if (count > size()) {
        if (count > capacity()) reserve(2 * count);
        for (size_t i = size(); i != count; ++i) 
            alloc.construct(first_free++, s);
    }
    else if (count < size()) {
        while (first_free != elements + count) 
            alloc.destroy(--first_free);
    }
}

int main() {
    return 0;
}

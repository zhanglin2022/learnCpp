#ifndef VEC_H
#define VEC_H

#include <memory>

template <typename T>
class Vec {
public:
    Vec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    Vec(std::initializer_list<T> l);    
    Vec(const Vec&);
    Vec& operator=(const Vec&);
    ~Vec();

    void push_back(const T&);

    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    T* begin() const { return elements; }
    T* end() const { return first_free; }

private:
    static std::allocator<T> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();
    
    T *elements;
    T *first_free;
    T *cap; 
};

// copy control
template <typename T>
Vec<T>::Vec(const Vec &s) {
    //call alloc_n_copy to allocate exactly as many elements as in s
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::Vec(std::initializer_list<T> l) {
    T* const newData = alloc.allocate(l.size());
    T* p = newData;
    for(const auto &t : l)
        alloc.construct(p++, t);
    elements = newData;
    first_free = cap = elements + l.size();
}

template <typename T>
Vec<T>::~Vec<T>() { free(); }

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
 
// member function
template <typename T>
void Vec<T>::push_back(const T &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free() {
    if (elements) {
        for (auto p = first_free; p != elements; /*empty*/)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
void Vec<T>::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements; 
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

// static member alloc
template <typename T>
std::allocator<T> Vec<T>::alloc;

#endif // VEC_H



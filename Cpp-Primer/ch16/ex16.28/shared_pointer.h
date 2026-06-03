// Refer to Exercise 13.53

#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <functional>

#include "delete.h"

namespace CP5 {
    template<typename T>
    class SharedPointer;

    template<typename T>
    void swap(SharedPointer<T> &lhs, SharedPointer<T> &rhs) {
        using std::swap;
        swap(lhs.ptr, rhs.ptr);
        swap(lhs.ref_count, rhs.ref_count);
        swap(lhs.deleter, rhs.deleter);
    }

    template<typename T>
    class SharedPointer {
    public:


    private:
        T *ptr;
        std::size_t* ref_count;
        std::function<void(T*)> deleter;

        auto decrement_and_destroy() {
            if (ptr && 0 == -*ref_count) {
                delete ref_count;
                deleter(ptr);
            }
            else if (!ptr)
                delete ref_count;
            ref_count = nullptr;
            ptr = nullptr;
        }    
    };

} // CP5

#endif // SHARED_PTR_H

// Refer to Exercise 13.53

#ifndef SHARED_POINTER_H
#define SHARED_POINTER_H

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
        // default constructor
        SharedPointer() : 
            ptr(nullptr), ref_count(nullptr), deleter(CP5::Delete()) { }
        // constructor that takes a raw pointer
        explicit SharedPointer(T *raw_ptr) : 
            ptr(raw_ptr), ref_count(raw_ptr ? new std::size_t(1) : nullptr), deleter(CP5::Delete()) { }
        // copy constructor
        SharedPointer(const SharedPointer &rhs) : 
            ptr(rhs.ptr), ref_count(rhs.ref_count), deleter(rhs.deleter) {
            if (ref_count) ++*ref_count;
        }
        // move constructor
        SharedPointer(const SharedPointer &&rhs) :
            ptr(rhs.ptr), ref_count(rhs.ref_count), deleter(std::move(rhs.deleter)) { 
            rhs.ptr = nullptr;
            rhs.ref_count = nullptr;
        }
        // copy assignment
        SharedPointer& SharedPointer(const SharedPointer &rhs) {
            if (this != &rhs) {
                if(rhs.ref_count) ++*rhs.ref_count;
                decrement_and_destroy();
                ptr = rhs.ptr;
                ref_count = rhs.ref_count;
                deleter = rhs.deleter;
            }
            return *this;
        }
        // move assignment
        SharedPointer& SharedPointer(const SharedPointer &&rhs) {
            if (this != &rhs) {
                decrement_and_destroy();
                ptr = rhs.ptr;
                ref_count = rhs.ref_count;
                deleter = std::move(rhs.deleter);
                rhs.ptr= nullptr;
                rhs.ref_count = nullptr;
            }
            return *this;
        }

        // member function
        operator bool() const {
            return ptr ? true : false;
        }

        T& operator*() const {
            return *ptr;
        }

        T* operator->() const {
            return &*ptr;
        }

        auto use_count() const {
            return ref_count ? *ref_count : 0;
        }

        auto get() const {
            return ptr;
        }

        auto unique() {
            return 1 == use_count();
        }

        auto swap(SharedPointer &rhs) {
            ::swap(*this, rhs);
        }

        // free the object pointed to, if unique
        auto reset() {
            decrement_and_destroy();
        }

        // reset the new raw pointer
        auto reset(T *pointer) {
            if (ptr != pointer) {
                decrement_and_destroy();
                ptr = pointer;
                ref_count = new std::size_t(1);
            }
        }

        // reset with raw pointer and deleter
        auto reset(T *pointer, const std::function<void(T*)> &d) {
            reset(pointer);
            deleter = d;
        }

    private:
        T *ptr;
        std::size_t* ref_count;
        std::function<void(T*)> deleter;
        // TODO 是否要修改
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

#endif // SHARED_POINTER_H

// Refer to Exercise 13.53

#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H

#include <functional>

#include "DebugDelete.h"

namespace CP5 {
    // forward declarations for friendship
    template <typename T>
    class SharedPointer;

    template <typename T>
    void swap(SharedPointer<T>&, SharedPointer<T>&);
    
    /**
     * @brief std::shared_ptr like class template
     */
    template <typename T>
    class SharedPointer {
        friend void swap<T>(SharedPointer<T>&, SharedPointer<T>&);

    public:
        // default constructor
        SharedPointer() : 
            ptr(nullptr), ref_count(nullptr), deleter(CP5::DebugDelete()) { }
        // constructor that takes a raw pointer
        explicit SharedPointer(T *raw_ptr) : 
            ptr(raw_ptr), ref_count(raw_ptr ? new std::size_t(1) : nullptr), deleter(CP5::DebugDelete()) { }
        // copy constructor
        SharedPointer(const SharedPointer &rhs) : 
            ptr(rhs.ptr), ref_count(rhs.ref_count), deleter(rhs.deleter) {
            if (ref_count) ++*ref_count;
        }
        // move constructor
        SharedPointer(SharedPointer &&rhs) noexcept :
            ptr(rhs.ptr), ref_count(rhs.ref_count), deleter(std::move(rhs.deleter)) { 
            rhs.ptr = nullptr;
            rhs.ref_count = nullptr;
        }
        // copy assignment
        SharedPointer& operator=(const SharedPointer &rhs) {
            if (this != &rhs) {
                if (rhs.ref_count) ++*rhs.ref_count;
                decrement_and_destroy();
                ptr = rhs.ptr;
                ref_count = rhs.ref_count;
                deleter = rhs.deleter;
            }
            return *this;
        }
        // move assignment
        SharedPointer& operator=(SharedPointer &&rhs) noexcept {
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
        // destructor
        ~SharedPointer() {
            decrement_and_destroy();
        }
        
        // member function
        operator bool() const { return ptr ? true : false; }
        T& operator*() const { return *ptr; }
        T* operator->() const { return ptr; }

        T* get() const { return ptr; }
        std::size_t use_count() const { return ref_count ? *ref_count : 0; }
        bool unique() const { return use_count() == 1; }
        void swap(SharedPointer &rhs) { CP5::swap(*this, rhs); }

        // free the object pointed to, if unique
        void reset() {
            decrement_and_destroy();
        }

        // reset the new raw pointer
        void reset(T *pointer) {
            if (ptr != pointer) {
                decrement_and_destroy();
                ptr = pointer;
                ref_count = pointer ? new std::size_t(1) : nullptr;
            }
        }

        // reset with raw pointer and deleter
        void reset(T *pointer, const std::function<void(T*)> &d) {
            reset(pointer);
            deleter = d;
        }

    private:
        T *ptr;
        std::size_t* ref_count;
        std::function<void(T*)> deleter;

        void decrement_and_destroy() {
            if (ref_count && --*ref_count == 0) {
                delete ref_count;
                deleter(ptr); 
            }
            ref_count = nullptr;
            ptr = nullptr;
        }    
    };

    template <typename T>
    inline void swap(SharedPointer<T> &lhs, SharedPointer<T> &rhs) {
        using std::swap;
        swap(lhs.ptr, rhs.ptr);
        swap(lhs.ref_count, rhs.ref_count);
        swap(lhs.deleter, rhs.deleter);
    }
} // CP5

#endif // SHAREDPOINTER_H

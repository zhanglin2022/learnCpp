#ifndef UNIQUEPOINTER_H
#define UNIQUEPOINTER_H

#include "DebugDelete.h"

namespace CP5 {
    // forward declarations for friendship
    template <typename T, typename D>
    class UniquePointer;

    template <typename T, typename D>
    void swap(UniquePointer<T, D>&, UniquePointer<T, D>&);

    /**
     * @brief std::unique_ptr like class template
     */
    template <typename T, typename D = CP5::DebugDelete>
    class UniquePointer {
        friend void swap<T, D>(UniquePointer<T, D>&, UniquePointer<T, D>&);

    public:
        // default constructor
        UniquePointer():
            ptr(nullptr), deleter(D()) { }
        // constructor that take a raw pointer
        UniquePointer(T *raw_ptr) : ptr(raw_ptr), deleter(D()) { }
        // prevent copy and assignment
        UniquePointer(const UniquePointer&) = delete;
        UniquePointer& operator=(const UniquePointer&) = delete;
        // move constructor
        UniquePointer(UniquePointer &&rhs) noexcept :
            ptr(rhs.ptr), deleter(std::move(rhs.deleter)) { 
            rhs.ptr = nullptr; 
        }
        // move assignment
        UniquePointer& operator=(UniquePointer &&rhs) noexcept {
            if (this != &rhs) {
                deleter(ptr);
                ptr = nullptr;
                CP5::swap(*this, rhs);
            }
            return *this;
        }
        // destructor
        ~UniquePointer() {
            deleter(ptr);
        }

        // member function
        operator bool() const { return ptr ? true : false; }
        T& operator*() const { return *ptr; }
        T* operator->() const { return ptr; }

        T* get() const { return ptr; }
        void swap(UniquePointer &rhs) { CP5::swap(*this, rhs); }


        void reset() { 
            deleter(ptr);
            ptr = nullptr;
        }

        void reset(T *pointer) {
            if (ptr != pointer) {
                deleter(ptr);
                ptr = pointer;
            }
        }

        // return ptr and make ptr point to nullptr.
        T* release() {
            T *ret = ptr;
            ptr = nullptr;
            return ret;
        }

    private:
        T *ptr;
        D deleter;
    };

    template <typename T, typename D>
    inline void swap(UniquePointer<T, D> &lhs, UniquePointer<T, D> &rhs) {
        using std::swap;
        swap(lhs.ptr, rhs.ptr);
        swap(lhs.deleter, rhs.deleter);
    }
} // CP5

#endif // UNIQUEPOINTER_H

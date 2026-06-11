#ifndef UNIQUEPOINTER_H
#define UNIQUEPOINTER_H

#include "delete.h"

namespace CP5 {
    // forward declarations for friendship
    template<typename T, typename D>
    class UniquePointer;

    template<typename T, typename D>
    void swap(UniquePointer<T, D>&, UniquePointer<T, D>&);

    /**
     * @brief std::unique_ptr like class template
     */
    template<typename T, typename D = CP5::Delete>
    class UniquePointer {
        friend void swap<T, D>(UniquePointer<T, D>&, UniquePointer<T, D>&);

    public:
        // default constructor
        UniquePointer():
            ptr(nullptr), deleter(D()) { }
        // constructor that take a raw pointer
        // TODO
        
    private:
        T *ptr;
        D deleter;
    };

}
#endif // UNIQUEPOINTER_H

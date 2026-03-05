// Exercise 14.32
//
// @See Exercise 14.30
//
// Define a class that holds a pointer to a StrBlobPtr. Define the overloaded 
// arrow operator for that class.
//

#ifndef EX14_32_H
#define EX14_32_H

class StrBlobPtr;

class StrBlobPtr_pointer {
public:    
    StrBlobPtr_pointer() = default;
    StrBlobPtr_pointer(StrBlobPtr *ptr) : pointer(ptr) { }

    StrBlobPtr& operator*() const;
    StrBlobPtr* operator->() const;

private: 
    StrBlobPtr *pointer = nullptr;
};

#endif

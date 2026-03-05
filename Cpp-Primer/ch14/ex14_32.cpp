// Exercise 14.32
//
// @See Exercise 14.30
//
// Define a class that holds a pointer to a StrBlobPtr. Define the overloaded 
// arrow operator for that class.
//

#include "ex14_32.h"
#include "ex14_30_StrBlob.h"
#include <iostream>

StrBlobPtr& StrBlobPtr_pointer::operator*() const {
    return *pointer;
}

StrBlobPtr* StrBlobPtr_pointer::operator->() const {
    return pointer;
}

int main() {
    StrBlob s1{"a", "b", "c"};
    StrBlobPtr iter = s1.begin();
    StrBlobPtr_pointer pp(&iter);

    // std::cout << pp->operator*() << std::endl;
    std::cout << pp->deref() << std::endl;

    return 0;
} 
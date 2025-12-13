//  Exercise 12_22
//
//  What changes would need to be made to StrBlobPtr to create a class
//  that can be used with a const StrBlob?
//  Define a class named ConstStrBlobPtr that can point to a const StrBlob.
//
//  @See    ex12_19.h

#include "ex12_22.h"
#include <iostream>

int main() {
    const StrBlob csb{"sun", "moon", "star"};
    ConstStrBlobPtr csbp(csb);
    std::cout << csbp.deref() << std::endl;
    csbp.incr();
    csbp.incr();
    std::cout << csbp.deref() << std::endl;

    return 0;
}
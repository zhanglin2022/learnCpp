// Exercise 14.26
//
// @See Exercise 14.18 StrBlob
//
// Define subscript operators for your StrVec, String, StrBlob, 
// and StrBlobPtr classes.

#include "ex14_26_StrBlob.h"
#include <iostream>

int main() {
    StrBlob S1{"Hello", "World"};
    StrBlob S2(S1);
    StrBlob S3{"C++", "Primer"};

    for (ConstStrBlobPtr iter = S3.cbegin(); iter != S3.cend(); iter.incr()) {
        std::cout << iter.deref() << " ";
    }
    std::cout << std::endl;

    std::cout << S1[0] << std::endl;
    std::cout << S3[1] << std::endl;

    return 0;
}

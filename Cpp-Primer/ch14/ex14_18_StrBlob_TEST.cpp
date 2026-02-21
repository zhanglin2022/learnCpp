// Exercise 14.18
// 
// @See Exercise 14.16
//
// Define relational operators for your StrBlob, StrBlobPtr, StrVec, and 
// String classes.
//

#include "ex14_18_StrBlob.h"
#include <iostream>

int main() {
    StrBlob S1{"Hello", "World"};
    StrBlob S2(S1);
    StrBlob S3{"C++", "Primer"};

    std::cout << (S1 < S2) << std::endl;
    std::cout << (S1 >= S3) << std::endl;

    for (ConstStrBlobPtr iter = S3.cbegin(); iter != S3.cend(); iter.incr()) {
        std::cout << iter.deref() << " ";
    }
    std::cout << std::endl;

    return 0;
}
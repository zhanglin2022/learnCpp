// Exercise 14.16
//
// @See Exercise 12.19, Exercise 12.22
//
// Define equality and inequality operators for your StrBlob (§ 12.1.1, p. 456), 
// StrBlobPtr (§ 12.1.6, p. 474), StrVec (§ 13.5, p. 526), and String (§ 13.5, p. 531)
// classes.
//

#include "ex14_16_StrBlob.h"
#include <iostream>

int main() {
    StrBlob S1{"Hello", "World"};
    StrBlob S2(S1);
    StrBlob S3{"C++", "Primer"};

    std::cout << (S1 == S2) << std::endl;
    std::cout << (S1 != S3) << std::endl;

    for (ConstStrBlobPtr iter = S3.cbegin(); iter != S3.cend(); iter.incr()) {
        std::cout << iter.deref() << " ";
    }
    std::cout << std::endl;

    return 0;
}
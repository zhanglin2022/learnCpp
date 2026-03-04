// Exercise 14.27 & 14.28
//
// @See Exercise 14.26 StrBlob
//
// Exercise 14.27: Add increment and decrement operators to your StrBlobPtr class.
//
// Exercise 14.28: Define addition and subtraction for StrBlobPtr so that these operators 
// implement pointer arithmetic (§ 3.5.3, p. 119).
//

#include "ex14_27_28_StrBlob.h"
#include <iostream>

int main() {
    StrBlob S1{"Hello", "World"};
    StrBlob S2(S1);
    StrBlob S3{"C++", "Primer", "5th", "Edition"};

    if (S2 > S3) {
        for (ConstStrBlobPtr iter = S2.cbegin(); iter != S2.cend(); ++iter)
            std::cout << iter.deref() << " ";
        std::cout << std::endl;
    }
    
    ConstStrBlobPtr iter(S3);
    std::cout << (iter + 2).deref() << std::endl;

    return 0;
}

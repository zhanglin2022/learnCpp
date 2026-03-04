// Exercise 14.30
// 
// @See Exercise 14.27
// 
// Add dereference and arrow operators to your StrBlobPtr class and to the 
// ConstStrBlobPtr class that you defined in exercise 12.22 from § 12.1.6 (p. 476). 
// Note that the operators in constStrBlobPtr must return const references 
// because the data member in constStrBlobPtr points to a const vector.
//

#include "ex14_30_StrBlob.h"
#include <iostream>

int main() {
    StrBlob S1{"Hello", "World"};
    StrBlob S2(S1);
    StrBlob S3{"C++", "Primer", "5th", "Edition"};

    S3[2] = "Fifth";
    
    if (S2 > S3) {
        for (ConstStrBlobPtr iter = S2.cbegin(); iter != S2.cend(); ++iter)
            std::cout << *iter << " ";
        std::cout << std::endl;
    }
    
    ConstStrBlobPtr iter(S3);
    std::cout << iter->size() << std::endl;

    return 0;
}

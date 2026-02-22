// Exercise 14.18
// 
// @See Exercise 14.16
//
// Define relational operators for your StrBlob, StrBlobPtr, StrVec, and 
// String classes.
//

#include "ex14_18_String.h"

int main() {
    String s1{"Hello"};
    String s2{"World"};

    std::cout << s1 << std::endl;
    std::cout << (s1 >= s2) << std::endl;

    return 0;
}

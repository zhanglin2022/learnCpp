// Exercise 14.26
//
// @See Exercise 14.18 String
//
// Define subscript operators for your StrVec, String, StrBlob, 
// and StrBlobPtr classes.

#include "ex14_26_String.h"

int main() {
    String s1{"Hello"};
    const String s2{"World"};

    std::cout << s1[2] << std::endl;
    std::cout << s2[2] << std::endl;

    return 0;
}

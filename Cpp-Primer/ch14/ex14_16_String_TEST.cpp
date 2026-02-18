// Exercise 14.16
//
// @See Exercise 14.7
//
// Define equality and inequality operators for your StrBlob (§ 12.1.1, p. 456), 
// StrBlobPtr (§ 12.1.6, p. 474), StrVec (§ 13.5, p. 526), and String (§ 13.5, p. 531)
// classes.
//

#include "ex14_16_String.h"

int main() {
    String s1{"Hello"};
    String s2{"World"};

    std::cout << s1 << std::endl;
    std::cout << (s1 == s2) << std::endl;

    return 0;
}

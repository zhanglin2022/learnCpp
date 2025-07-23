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
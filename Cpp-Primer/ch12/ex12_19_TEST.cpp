#include "./ex12_19.h"
#include <iostream>

using std::cout; using std::endl;

int main() {
    StrBlob sb{"sun", "moon", "star"};
    StrBlobPtr sbp(sb.begin());
    
    cout << sbp.deref() << endl;
    sbp.incr();
    cout << sbp.deref() << endl;

    return 0;
}
// Exercise 13.17
// 
// Write versions of numbered and f corresponding to the previous three exercises 
// and check whether you correctly predicted the output.
//

#include <iostream>

using namespace std;

class numbered {
public:
    numbered() { mysn = unique++; }
    numbered(const numbered&) { mysn = unique++; }
    int mysn;
    static int unique;
};

int numbered::unique = 10;

void f(const numbered &s) { 
    std::cout << s.mysn << std::endl; 
}

int main() {
    // a.mysn=10,unique=11; b.mysn=11,unique=12; c.mysn=12, unique=13
    numbered a, b = a, c = b;
    f(a); // mysn = 10
    f(b); // mysn = 11
    f(c); // mysn = 12

    return 0;
}

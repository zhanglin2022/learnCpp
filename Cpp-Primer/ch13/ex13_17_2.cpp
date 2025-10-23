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

void f(numbered s) { 
    std::cout << s.mysn << std::endl; 
}

int main() {
    // a.mysn=10,unique=11; b.mysn=11,unique=12; c.mysn=12, unique=13
    f(a); // mysn = 13
    f(b); // mysn = 14
    f(c); // mysn = 15

    return 0;
}

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
    int mysn;
    static int unique;
};

int numbered::unique = 10;

void f(numbered s) { 
    std::cout << s.mysn << std::endl; 
}

int main() {
    numbered a, b = a, c = b;
    f(a); 
    f(b); 
    f(c);

    return 0;
}

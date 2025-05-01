#include <iostream>

using std::cout;
using std::endl;

int abs(int val) {
    return val > 0 ? val : -val;
}

int main() {
    cout << abs(-3) << endl;
    return 0;
}
#include <iostream>
#include <stdexcept>

using std::runtime_error;
using std::boolalpha;
using std::cout;
using std::endl;

int fact(int val) {
    if (val < 0) {
        runtime_error err("Input can not be negative");
        cout << err.what() << endl;
    }
    int ret;
    for(ret = 1; val > 1; --val)
        ret *= val;
    return ret;
    // return val > 1 ? val * fact(val - 1) : 1;
}

int main() {
    cout << boolalpha << (120 == fact(5)) << endl;
    return 0;
}
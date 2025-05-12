#include <iostream>

using std::cout;
using std::endl;

int larger_one(const int i, const int *const p) {
    return (i >= *p) ? i : *p;
}

int main() {
    int i = 5;
    cout << "The larger one is: " << larger_one(3, &i) << endl;
    return 0;
}

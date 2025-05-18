#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::cerr;
using Iter = vector<int>::const_iterator;
void printVec(vector<int> &vec) {
#ifndef NDEBUG
cerr << __func__ << ": vector size is " << vec.size() << endl;
#endif
    if (!vec.empty()) {
        auto tmp = vec.back();
        vec.pop_back();
        printVec(vec);
        cout << tmp << " ";
    }
}

int main() {
    vector<int> vec{0, 1, 2, 3, 4, 5};
    printVec(vec);
    cout << endl;

    return 0;
}

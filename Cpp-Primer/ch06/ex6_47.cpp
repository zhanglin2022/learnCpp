// Exercise 6.47
//
// Revise the program you wrote in the exercises in § 6.3.2 (p. 228) that 
// used recursion to print the contents of a vector to conditionally print 
// information about its execution. For example, you might print the size 
// of the vector on each call. Compile and run the program with debugging 
// turned on and again with it turned off.
//

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

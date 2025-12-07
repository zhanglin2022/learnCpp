// Exercise 6.55 and Exercise 6.56
//
// Exercise 6.55:  Write four functions that add, subtract, multiply, and 
// divide two int values. 
// Store pointers to these functions in your vector from the previous exercise.
//
// Exercise 6.56： Call each element in the vector and print their result.
//

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

inline int f(const int, const int);
typedef decltype(f) fp; // fp is a function type not a function pointer

inline int numAdd (const int a, const int b) { return a + b; }
inline int numSub (const int a, const int b) { return a - b; }
inline int numMul (const int a , const int b) { return a * b; }
inline int numDiv (const int a, const int b) { return b != 0 ? a / b : 0; }

vector<fp*> v{numAdd, numSub, numMul, numDiv};

int main() {
    for (auto it : v) 
        cout << (*it)(2, 2) << endl;
    return 0;
}
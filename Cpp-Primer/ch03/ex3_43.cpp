// Exercise 3.43
//
// Write three different versions of a program to print the elements of ia. 
// One version should use a range for to manage the iteration, the other two 
// should use an ordinary for loop in one case using subscripts and in the 
// other using pointers. In all three programs write all the types directly. 
// That is, do not use a type alias, auto, or decltype to simplify the code.
//

#include <iostream>

using std::cout;
using std::endl;

int main() {
    int ia[3][4] = {
        {0, 1, 2, 3}, 
        {4, 5, 6, 7}, 
        {8, 9, 10, 11}
    };
    size_t rowCnt = 3, colCnt = 4;

    // range for
    for (const int (&p)[4] : ia)
        for (const int &q : p)
            cout << q << " ";
    cout << endl;

    // for loop using subscripts
    for (size_t i = 0; i != rowCnt; ++i)
        for (size_t j = 0; j != colCnt; ++j)
            cout << ia[i][j] << " ";
    cout << endl;

    // for loop using pointers
    for (int (*p)[4] = ia; p != ia + rowCnt; ++p)
        for (int *q = *p ; q != *p + colCnt; ++q)
            cout << *q << " ";
    cout << endl;

    return 0;
}
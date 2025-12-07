// Exercise 3.44
//
// Rewrite the programs from the previous exercises using a type alias for 
// the type of the loop control variables.
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
    // using type alias
    using int_array = int[4];
    for (int_array &p : ia)
        for (const int &q : p)
            cout << q << " ";
    cout << endl;

    // for loop using subscripts
    for (size_t i = 0; i != rowCnt; ++i)
        for (size_t j = 0; j != colCnt; ++j)
            cout << ia[i][j] << " ";
    cout << endl;

    // for loop using pointers
    // using type alias
    for (int_array *p = ia; p != ia + rowCnt; ++p)
        for (int *q = *p ; q != *p + colCnt; ++q)
            cout << *q << " ";
    cout << endl;

    return 0;
}
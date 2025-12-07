// Exercise 3.45
// 
// Rewrite the programs again, this time using auto.
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
    // using auto
    for (auto &p : ia)
        for (auto &q : p)
            cout << q << " ";
    cout << endl;

    // for loop using subscripts
    // using auto
    for (auto i = 0; i != rowCnt; ++i)
        for (auto j = 0; j != colCnt; ++j)
            cout << ia[i][j] << " ";
    cout << endl;

    // for loop using pointers
    // using auto
    for (auto p = ia; p != ia + rowCnt; ++p)
        for (auto q = *p ; q != *p + colCnt; ++q)
            cout << *q << " ";
    cout << endl;

    return 0;
}
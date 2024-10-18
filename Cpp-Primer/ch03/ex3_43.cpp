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
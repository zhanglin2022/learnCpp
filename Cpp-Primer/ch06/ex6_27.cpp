#include <iostream>
#include <initializer_list>

using std::initializer_list;
using std::cout;
using std::endl;

int para_nums (initializer_list<int> &il) {
    int sum = 0;
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        sum += *beg;
        return sum;
}

int main() { 
    auto li = {1, 2, 3, 4, 5};
    cout << para_nums(li) << endl;
    return 0;
}
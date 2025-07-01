#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using std::vector; using std::list; using std::cout; using std::endl;
using std::back_inserter; using std::front_inserter; using std::inserter;

void println(const list<int> &lst) {
    for (const auto &l : lst)
        cout << l << " ";
    cout << endl;
}

int main() {
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> lst1, lst2, lst3;
    std::copy(ivec.cbegin(), ivec.cend(), back_inserter(lst1));
    std::copy(ivec.cbegin(), ivec.cend(), front_inserter(lst2));
    std::copy(ivec.cbegin(), ivec.cend(), inserter(lst3, lst3.begin()));
    println(lst1);
    println(lst2);
    println(lst3);

    return 0;
}
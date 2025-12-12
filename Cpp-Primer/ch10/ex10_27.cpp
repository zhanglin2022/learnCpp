// Exercise 10.27
// 
// In addition to unique (§ 10.2.3, p. 384), the library defines function 
// named unique_copy that takes a third iterator denoting a destination into 
// which to copy the unique elements. 
// Write a program that uses unique_copy to copy the unique elements from 
// a vector into an initially empty list.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using std::vector; using std::list; using std::cout; using std::endl;

int main() {
    vector<int> ivec{0, 1, 1, 3, 5, 5};
    list<int> ilst;
    std::unique_copy(ivec.begin(), ivec.end(), std::back_inserter(ilst));

    for (auto i : ilst) 
        cout << i << " ";
    cout << endl;

    return 0;
}
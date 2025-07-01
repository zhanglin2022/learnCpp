#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include<iterator>

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
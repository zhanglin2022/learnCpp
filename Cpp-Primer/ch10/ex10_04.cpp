// Exercise 10.4
// 
// Assuming v is a vector<double>, what, if anything, is wrong with calling 
// accumulate(v.cbegin(), v.cend(), 0)?
//

#include <iostream>
#include <vector>
#include <numeric>

using std::vector; using std::cout; using std::endl;

int main() {
    vector<double> ivec{1.6, 2.6, 3.7};
    // cout 6 rather than 7.9
    cout << std::accumulate(ivec.cbegin(), ivec.cend(), 0) << endl;

    return 0;
}
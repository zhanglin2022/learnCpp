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
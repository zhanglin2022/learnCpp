#include <iostream>
#include <vector>
#include <algorithm>

using std::fill_n; using std::vector; using std::cout; using std::endl;

int main() {
    vector<int> ivec{0, 1, 2, 3, 4, 5};
    fill_n(ivec.begin(), ivec.size(), 0);
    for (const auto i : ivec) cout << i << " ";
    cout << endl;

    return 0;
}
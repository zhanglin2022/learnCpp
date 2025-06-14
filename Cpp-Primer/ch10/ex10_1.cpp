#include <iostream>
#include <vector>
#include <algorithm>

using std::vector; using std::count; using std::cout; using std::endl;

int main() {
    vector<int> ivec{2, 3, 3, 2, 5};
    auto cnt = count(ivec.begin(), ivec.end(), 3);
    cout << cnt << endl;

    return 0;
}
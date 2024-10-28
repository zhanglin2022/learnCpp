#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main () {
    vector<int> ivec{1, 2, 3, 5, 6};
    for (auto i : ivec) {
        cout << ((i & 0x1) ? i * 2 : i) << " ";
    }
    cout << endl;
    return 0;
}
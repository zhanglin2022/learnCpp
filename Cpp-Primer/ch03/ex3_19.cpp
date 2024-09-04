#include <vector>

using std::vector;

int main() {
    vector<int> ivec1(10, 42); // The first way is better
    vector<int> ivec2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    vector<int> ivec3;
    for (int i = 0; i < 10; ++i) ivec3.push_back(i);
    return 0;
}
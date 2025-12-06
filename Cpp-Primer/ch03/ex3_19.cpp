// Exercise 3.19
// 
// List three ways to define a vector and give it ten elements, each with the 
// value 42. Indicate whether there is a preferred way to do so and why.
//

#include <vector>

using std::vector;

int main() {
    vector<int> ivec1(10, 42); // The first way is better
    vector<int> ivec2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    vector<int> ivec3;
    for (int i = 0; i < 10; ++i) ivec3.push_back(i);
    return 0;
}
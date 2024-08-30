#include <vector>
#include <iostream>

using std::vector;
using std::cin;

int main() {
    vector<int> vec;
    for(int num = 0; cin >> num; vec.push_back(num));
    return 0;
}

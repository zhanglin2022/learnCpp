// Exercise 3.24
//
// Redo the last exercise from § 3.3.3 (p. 105) using iterators.
//

#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<int> ivec;
    for(int num = 0; cin >> num; ivec.push_back(num));

    if (ivec.size() < 2) {
        cout << "please enter at least 2 integers";
        return -1;
    }
    for (auto it = ivec.cbegin(); it != ivec.cend() - 1; ++it)
        cout << *it + *(it+1) << " ";
    cout << endl;

    for (auto lft = ivec.cbegin(), rht = ivec.cend() - 1; lft < rht; ++lft, --rht)
        cout << *lft + *rht << " ";
    cout << endl;

    return 0;
}
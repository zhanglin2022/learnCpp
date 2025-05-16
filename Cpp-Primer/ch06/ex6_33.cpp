#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using Iter = vector<int>::const_iterator;
void print(Iter beg, Iter end) {
    if (beg != end) {
        cout << *beg << " ";
        print(++beg, end);
    }
}

int main() {
    vector<int> vec{0, 1, 2, 3, 4, 5};
    print(vec.cbegin(), vec.cend());
    cout << endl;

    return 0;
}

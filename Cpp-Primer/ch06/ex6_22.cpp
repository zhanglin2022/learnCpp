#include <iostream>

using std::cout;
using std::endl;

void swap(int*& lft, int *& rht) {
    auto tmp = lft;
    lft = rht;
    rht = tmp;
}

int main() {
    int i = 50, j = 70;
    auto lft = &i, rht = &j;
    swap(lft, rht);
    cout << *lft << " " << *rht << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector; using std::count_if; using std::cout; using std::endl;

int main() {
    int i = 6;
    auto check_and_decrement = [&i] () -> bool { return i > 0 ? !--i : !i; };
    while (!check_and_decrement()) cout << i << " ";
    cout << endl;

    return 0;
}
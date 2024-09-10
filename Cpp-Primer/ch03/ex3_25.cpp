#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<int> score(11, 0);
    for (unsigned grade; cin >> grade; /* */) {
        if (grade <= 100)
            ++*(score.begin() + grade / 10);
    }

    for (auto s: score)
        cout << s << " ";
    cout << endl;

    return 0;
}
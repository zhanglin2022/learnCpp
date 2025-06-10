#include <iostream>
#include <vector>
#include <list>

using std::vector; using std::list; using std::cout; using std::endl; using std::end;

int main() {
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    vector<int> vec(ia, end(ia));
    list<int> lst(vec.cbegin(), vec.cend());
    // remove odd value
    for (auto it = lst.begin(); it != lst.end();) {
        if (*it & 0x1) it = lst.erase(it);
        else ++it;
    }
    // remove even values
    for (auto it = vec.begin(); it != vec.end();) {
        if (!(*it & 0x1)) it = vec.erase(it);
        else ++it;
    }
    // print list
    for (auto l : lst) cout << l << " ";
    cout << endl;
    // print vector
    for (auto v : vec) cout << v << " ";
    cout << endl;

    return 0;
}
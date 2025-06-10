#include <iostream>
#include <list>
#include <deque>

using std::list; using std::deque; using std::cout; using std::endl;

int main() {
    list<int> input{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> odd, even;
    for(const auto i : input)
        (i & 0x1 ? odd : even).push_back(i); 
    for (auto o : odd) cout << o << " ";
    cout << endl;
    for (auto e : even) cout << e << " ";
    cout << endl;

    return 0; 
}
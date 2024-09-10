#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> vec(10, 5);
    cout << "The twice vector is: [";
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        (*it) *= 2;
        cout << *it << (it != vec.end() -1 ? "," : "");
    }
    cout << "]" << endl;
    return 0;
}
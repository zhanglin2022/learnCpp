#include <iostream>
#include <string>
#include <vector>

using std::string; using std::vector; using std::cout; using std::endl;

int main() {
    vector<char> cvec{'a', 'b', 'c'};
    string  str(cvec.begin(), cvec.end());
    cout << str << endl;

    return 0;
}
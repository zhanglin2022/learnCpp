#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

int main() {
    vector<int> vec;
    cout << vec.at(0);      // terminate called after throwing an instance of 'std::out_of_range'
    cout << vec[0];         // Segmentation fault
    cout << vec.front();    // Segmentation fault
    cout << *vec.begin();      // Segmentation fault
    return 0;
}
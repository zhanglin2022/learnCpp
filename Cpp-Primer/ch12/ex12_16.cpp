#include <iostream>
#include <memory>

using std::unique_ptr; using std::cout; using std::endl;
int main() {
    unique_ptr<int> p1(new int(23));
    // unique_ptr<int> p2(p1);    // error: use of deleted function p1
    // unique_ptr<int> p3 = p1;   // error: use of deleted function p1
    cout << *p1 << endl;
    
    return 0;
}
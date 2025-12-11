// Exercise 9.38
//
// Write a program to explore how vectors grow in the library you use.
//

#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

int main() {
    vector<int> ivec;
    // init size and capacity
    cout << "ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;
    // give ivec 24 elements
    for (vector<int>::size_type ix = 0; ix != 24; ++ix) 
        ivec.push_back(ix);
    // size should be 24; capacity will be >= 24 and is implementation defined 
    cout << "ivec: size: " << ivec.size() 
         << " capacity: " << ivec.capacity() << endl;
    // reserve some addition space
    ivec.reserve(50);
    cout << "ivec: size: " << ivec.size() 
         << " capacity: " << ivec.capacity() << endl;
    // use up that reserved capacity
    while (ivec.size() != ivec.capacity())
        ivec.push_back(0);
    cout << "ivec: size: " << ivec.size() 
         << " capacity: " << ivec.capacity() << endl;
    // if we add another element, the vector will reallocate iterself
    ivec.push_back(20);
    cout << "ivec: size: " << ivec.size() 
         << " capacity: " << ivec.capacity() << endl;

    return 0;
}
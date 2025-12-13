// Exercise 12.6
//
// Write a function that returns a dynamically allocated vector of ints. 
// Pass that vector to another function that reads the standard input to 
// give values to the elements. 
// Pass the vector to another function to print the values that were read. 
// Remember to delete the vector at the appropriate time.
//

#include <iostream>
#include <new>
#include <vector>

using std::vector; using std::cin; using std::cout; using std::endl;
using Ptr = vector<int>*;

Ptr returnDmcVec() {
    return new vector<int> {};
}

Ptr assign(Ptr vec) {
    for (int i; cout << "Please Enter:\n", cin >> i; vec->push_back(i));
    return vec;
}

std::ostream& print(Ptr vec) {
    for (const auto i : *vec) cout << i << " ";
    return cout;
}

int main() {
    auto vec = assign(returnDmcVec());
    print(vec) << endl;
    delete vec;

    return 0;
}
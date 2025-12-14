//  Exercise 13.31 
//
// Give your class a < operator and define a vector of HasPtrs. Give that
// vector some elements and then sort the vector. Note when swap is called.
//

#include "ex13_31.h"
#include <vector>
#include <algorithm>

int main() {
    HasPtr s("s"), c("c"), i("i");
    std::vector<HasPtr> vec{s, c, i};
    std::sort(vec.begin(), vec.end());

    for (auto const& i : vec) i.print(); 
    
    return 0;
}
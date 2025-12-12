// Exercise 10.37
// 
// Given a vector that has ten elements, copy the elements from positions 
// 3 through 7 in reverse order to a list
// 

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main() {
    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> rlst(8 - 3);
    std::copy(vec.cbegin() + 3, vec.cbegin() + 8, rlst.rbegin());   
    //     0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    //           ^              ^
    //          rend          rbegin
    // @note: std::copy copies the range [first, last) into result.
    //        hence, the arguments here denote:
    //        [7 6 5 4 3 2)
    //                   ^ this one is specified but not included. 
    for (auto i : rlst) std:: cout << i << " ";
    std::cout << std::endl;
    
    return 0;
}
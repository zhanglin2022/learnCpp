// Exercise 5.17
//
// Given two vectors of ints, write a program to determine whether one vector is a 
// prefix of the other. For vectors of unequal length, compare the number of elements 
// of the smaller vector. 
// For example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8, 
// respectively your program should return true.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

bool is_prefix(vector<int> const& lvec, vector<int> const& rvec) {
    if(lvec.size() > rvec.size())
        return is_prefix(rvec, lvec);
    for (unsigned i = 0; i != lvec.size(); ++ i)
        if (lvec[i] != rvec[i]) return false;
    return true;
}

int main() {
    vector<int> lvec{0, 1, 1, 2};
    vector<int> rvec{0, 1, 1, 2, 3, 5, 8};
    cout << (is_prefix(lvec, rvec) ? "yes" : "no") << endl;
    return 0;
}
// Exercise 10.13
//
// The library defines an algorithm named partition that takes a predicate 
// and partitions the container so that values for which the predicate is 
// true appear in the first part and those for which the predicate is false 
// appear in the second part. 
//
// The algorithm returns an iterator just past the last element for which 
// the predicate returned true. Write a function that takes a string and 
// returns a bool indicating whether the string has five characters or more. 
//
// Use that function to partition words. Print the elements that have five 
// or more characters.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::partition; using std::string; using std::cout; using std::endl; using std::vector;

bool comparelen(const string &str) {
    return str.size() >= 5;
}

int main() {
    vector<string> svec{"aaaa", "aaaaa", "333", "666666"};
    auto pivot = partition(svec.begin(), svec.end(), comparelen);

    for (auto it = svec.cbegin(); it != pivot; ++it) cout << *it << " ";
    cout << endl;

    return 0;
}

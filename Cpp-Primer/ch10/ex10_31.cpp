// Exercise 10.31
//
// Update the program from the previous exercise so that it prints only the 
// unique elements. 
// Your program should use unqiue_copy (§ 10.4.1, p. 403).
//

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl; using std::istream_iterator; using std::ostream_iterator;

int main() {
    istream_iterator<int> in_iter(cin), eof;
    std::vector<int> vec(in_iter, eof);
    std::sort(vec.begin(), vec.end());
    std::unique_copy(vec.cbegin(), vec.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
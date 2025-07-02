#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl; using std::istream_iterator; using std::ostream_iterator;

int main() {
    istream_iterator<int> in_iter(cin), eof;
    std::vector<int> vec(in_iter, eof);
    std::sort(vec.begin(), vec.end());
    std::copy(vec.cbegin(), vec.cend(), ostream_iterator<int>(cout, " "));

    return 0;
}
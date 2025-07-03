#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using std::vector; using std::string; using std::cout; using std::endl; 
using std::istream_iterator; using std::ostream_iterator; using std::ifstream;

int main() {
    ifstream ifs("../../data/book.txt");
    istream_iterator<string> in_iter(ifs), eof;
    vector<string> svec;
    copy(in_iter, eof, back_inserter(svec));  
    copy(svec.cbegin(), svec.cend(), ostream_iterator<string>(cout, "\n"));
    return 0;
}
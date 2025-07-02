#include "../include/Sales_item.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using std::vector; using std::string; using std::cin; using std::cout; using std::endl;
using std::istream_iterator; using std::find_if;

bool compareisbn(const Sales_item &item1, const Sales_item &item2) {
    return item1.isbn() < item2.isbn();
}

int main() {
    istream_iterator<Sales_item> in_inter(cin), eof;
    vector<Sales_item> svec;

    while (in_inter != eof)
        svec.push_back(*in_inter++);
    std::sort(svec.begin(), svec.end(), compareisbn);
    for (auto beg = svec.cbegin(), end = beg; beg != svec.cend(); beg=end) {
        end = find_if(beg, svec.cend(), [beg](const Sales_item &item) { return item.isbn() != beg->isbn(); });
        cout << std::accumulate(beg, end, Sales_item(beg->isbn())) << endl;
    }
    return 0;
}
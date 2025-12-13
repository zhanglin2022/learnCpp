// Exercise 11.10
//
// Could we define a map from vector<int>::iterator to int? What about from 
// list<int>::iterator to int? In each case, if not, why not?
//

#include <map>
#include <vector>
#include <list>

using std::vector; using std::list;

int main() {
    // can be declared
    std::map<vector<int>::iterator, int> mv;
    std::map<list<int>::iterator, int> ml;

    vector<int> v1;
    mv.insert(std::pair<vector<int>::iterator, int>(v1.begin(), 0));

    // error: no match for ‘operator<’ in '__x < __y'
    list<int> l1;
    ml.insert(std::pair<list<int>::iterator, int>(l1.begin(), 0));

    return 0;
}
#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using std::list; using std::string; using std::count; using std::cout; using std::endl;

int main() {
    list<string> slst{"sun", "su", "sunny", "sun"};
    cout << count(slst.begin(), slst.end(), "sun") << endl;

    return 0;
}
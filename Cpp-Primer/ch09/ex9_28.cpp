// Exercise 9.28
//
// Write a function that takes a forward_list<string> and two additional 
// string arguments. 
// The function should find the first string and insert the second immediately 
// following the first. 
// If the first string is not found, then insert the second string at the end
//  of the list.
//

#include <iostream>
#include <string>
#include <forward_list>

using std::string; using std::forward_list; using std::cout; using std::endl;

void inserStr(forward_list<string> &flst, const string &to_find, const string &to_add) {
    auto prev = flst.before_begin();
    for(auto curr = flst.begin(); curr != flst.end(); prev = curr++) {
        if(*prev == to_find) {
            flst.insert_after(prev, to_add);
            return;
        }
    }
    flst.insert_after(prev, to_add);
}

int main() {
    forward_list<string> flst{"fire", "sun", "boat", "flower"};
    inserStr(flst, "sun", "moon");
    // inserStr(flst, "star", "moon");
    for (auto f : flst) cout << f << " ";
    cout << endl;

    return 0;
}
// Exercise 9.31
//
// The program on page 354 to remove even-valued elements and duplicate odd 
// ones will not work on a list or forward_list. Why? 
// Revise the program so that it works on these types as well.
//

#include <iostream>
#include <forward_list>

using std::forward_list; using std::cout; using std::endl; using std::advance;

auto remove_evens_and_double_odds(forward_list<int>& data) {
    auto pre = data.before_begin();
    for (auto cur = data.begin(); cur != data.end();) {
        if (*cur & 0x1) {
            cur = data.insert_after(pre, *cur);
            advance(pre, 2);
            advance(cur, 2);
        } else {
            cur = data.erase_after(pre);
        }
        
    }
}

int main() {
    forward_list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    remove_evens_and_double_odds(fli);
    for (auto i : fli) cout << i << " ";
    cout << endl;
}
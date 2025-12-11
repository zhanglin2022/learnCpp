// Exercise 9.19
//
// Rewrite the program from the previous exercise to use a list. 
// List the changes you needed to make.
//

#include <iostream>
#include <string>
#include <list>

using std:: cin; using std::cout; using std::endl; using std::string; using std::list;

int main() {
    list<string> input;
    for(string str; cin >> str; input.push_back(str));
    for (auto it = input.cbegin(); it != input.cend(); ++it)
        cout << *it << endl;

    return 0;
}
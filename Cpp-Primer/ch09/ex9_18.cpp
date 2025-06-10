#include <iostream>
#include <string>
#include <deque>

using std:: cin; using std::cout; using std::endl; using std::string; using std::deque;

int main() {
    deque<string> input;
    for(string str; cin >> str; input.push_back(str));
    for (auto it = input.cbegin(); it != input.cend(); ++it)
        cout << *it << endl;

    return 0;
}
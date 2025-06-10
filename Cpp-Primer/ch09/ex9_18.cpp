#include <iostream>
#include <string>
#include <deque>

using std:: cin; using std::cout; using std::endl; using std::string; using std::deque;

int main() {
    deque<string> dqe;
    for(string str; cin >> str; dqe.push_back(str));
    for (auto it = dqe.cbegin(); it != dqe.cend(); ++it)
        cout << *it << endl;

    return 0;
}
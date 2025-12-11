// Exercise 9.18
//
// Write a program to read a sequence of strings from the standard input 
// into a deque. 
// Use iterators to write a loop to print the elements in the deque.
//

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
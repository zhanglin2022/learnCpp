// Exercise 3.8
//
// Rewrite the program in the first exercise, first using a while and again 
// using a traditional for loop. Which of the three approaches do you prefer 
// and why?

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main() {
    string str("a initial string");
    decltype(str.size()) idx = 0;

    // while
    while (idx < str.size()) str[idx++] = 'X';
    cout << str << endl;

    // // for
    // for (idx = 0 ; idx < str.size() ; str[idx++] = 'X');
    // cout << str << endl;

    return 0;
}
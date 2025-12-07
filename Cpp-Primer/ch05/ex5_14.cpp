// Exercise 5.14
// 
// Write a program to read strings from standard input looking for duplicated words. 
// The program should find places in the input where one word is followed immediately 
// by itself. 
// Keep track of the largest number of times a single repetition occurs and which word 
// is repeated. 
// Print the maximum number of duplicates, or else print a message saying that no word 
// was repeated. For example, if the input is:
// "how now now now brown cow cow"
// the output should indicate that the word now occurred three times.
// 

#include<iostream>
#include<string>

using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

int main() {
    pair<string, int> max_duplicated;
    unsigned cnt = 0;
    for(string str, prestr; cin >> str; prestr = str) {
        if (str == prestr) ++cnt;
        else cnt = 0;
        if (cnt > max_duplicated.second) max_duplicated = {prestr, cnt};
    }
    if (max_duplicated.first.empty()) cout << "No word was repeated." << endl;
    else cout << "The word " << max_duplicated.first << " occured " 
              << max_duplicated.second + 1 << " times." << endl;

    return 0;
}
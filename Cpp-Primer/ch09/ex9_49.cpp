// Exercise 9.49
//
// A letter has an ascender if, as with d or f, part of the letter extends 
// above the middle of the line. A letter has a descender if, as with p or g, 
// part of the letter extends below the line. 
// Write a program that reads a file containing words and reports the longest 
// word that contains neither ascenders nor descenders.
//

#include <iostream>
#include <string>
#include <fstream>

using std::string; using std::ifstream; using std::cout; using std::endl; using std::cerr;

int main() {
    ifstream ifs("../../data/phone.txt");
    string asde("bdfghjklpqty");
    string loggest;

    if (!ifs) return -1;
    for (string word; ifs >> word; ) {
        if (word.find_first_of(asde) != string::npos) {
            loggest = word.size() > loggest.size() ? word : loggest;
        }
    }
    cout << loggest << endl;
    
    return 0;
}
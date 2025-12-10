// Exercise 8.4
//
// Write a function to open a file for input and read its contents into a 
// vector of strings, storing each line as a separate element in the vector.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

void readFileToVec(const string& filename, vector<string>& vec) {
    ifstream ifs(filename);
    if (ifs) {
        string buf;
        while (getline(ifs, buf))
            vec.push_back(buf);    
    }
}

int main() {
    vector<string> vec;
    readFileToVec("../../data/book.txt", vec);
    for (const auto &str : vec)
        cout << str << endl;
    return 0;
}

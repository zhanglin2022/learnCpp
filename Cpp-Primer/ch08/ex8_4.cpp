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
    readFileToVec("../data/book.tex", vec);
    for (const auto &str : vec)
        cout << str << endl;
    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

int main() {
    ifstream ifs("../../data/book.txt");
    if (!ifs) {
        std::cerr << "No data?" << std::endl;
        return -1;
    }

    vector<string> vecLine;
    string line;
    while(getline(ifs, line)) {
        vecLine.push_back(line);
    }

    for (auto &s : vecLine) {
        istringstream iss(s);
        string word;
        while (iss >> word) 
            std::cout << word << std::endl;
    }

    return 0;
}

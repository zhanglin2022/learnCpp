// Exercise 12.20
//
// Write a program that reads an input file a line at a time into a StrBlob 
// and uses a StrBlobPtr to print each element in that StrBlob.
//

#include "ex12_19.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cin; using std::cout; using std::endl; using std::ifstream;
using std::string; using std::istringstream;

int main() {
    StrBlob blob;
    ifstream ifs("../../data/book.txt");
    if (!ifs) std::cerr << "No data?" << std::endl;
    for (string text; getline(ifs, text); )
        blob.push_back(text);
    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
        cout << pbeg.deref() << endl;

    return 0;
}
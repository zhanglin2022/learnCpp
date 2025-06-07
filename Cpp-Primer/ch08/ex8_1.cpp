#include <iostream>
#include <string>

using std::string;
using std::istream;

istream& func(istream &is) {
    string buf;
    while(is >> buf) 
        std::cout << buf << std::endl;
    
    is.clear();
    return is;
}
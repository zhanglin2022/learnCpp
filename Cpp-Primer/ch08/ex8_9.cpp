#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::istream;
using std::istringstream;

istream& func(istream &is) {
    string buf;
    while(is >> buf) 
        std::cout << buf << std::endl;
    
    is.clear();
    return is;
}

int main() {
    string str("Sun and Moon");
    istringstream record(str);
    func(record);

    return 0;
}
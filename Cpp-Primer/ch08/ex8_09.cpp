// Exercise 8.9
//
// Use the function you wrote for the first exercise in § 8.1.2 (p. 314) 
// to print the contents of an istringstream object.
//

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
// Exercise 14.35
//
// Write a class like PrintString that reads a line of input from an 
// istream and returns a string representing what was read. If the read 
// fails, return the empty string.
//

#include <iostream>
#include <string>

class GetInput {
public:
    GetInput(std::istream &i = std::cin) : is(i) { }
    std::string operator()() const {
        std::string str;
        std::getline(is, str);
        return is ? str : std::string();
    } 

private:
    std::istream &is;
};

int main() {
    GetInput getinput;
    std::cout << getinput() << std::endl;
}

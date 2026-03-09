// Exercise 14.36
//
// @See Exercise 14.35
//
// Use the class from the previous exercise to read the standard input, 
// storing each line as an element in a vector.
//

#include <iostream>
#include <string>
#include <vector>

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
    std::vector<std::string> svec;

    for (std::string tmp; !(tmp = getinput()).empty();) svec.push_back(tmp);
    for (const auto &s : svec) std::cout << s << " ";
    std::cout << std::endl;

    return 0;
}

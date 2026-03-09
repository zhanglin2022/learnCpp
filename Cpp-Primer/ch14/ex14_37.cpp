// Exercise 14.37
//
// Write a class that tests whether two values are equal. Use that object 
// and the library algorithms to write a program to replace all instances 
// of a given value in a sequence.
//

#include <iostream>
#include <vector>
#include <algorithm>

class IsEqual{
public:
    IsEqual(int v) : value(v) { }
    bool operator()(int x) {
        return value == x;
    }
    
private:
    int value;
};

int main() {
    std::vector ivec{1, 3, 5, 7, 9};
    std::replace_if(ivec.begin(), ivec.end(), IsEqual(3), 20);
    for(const auto &i : ivec) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

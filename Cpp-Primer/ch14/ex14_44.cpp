// Exercise 14.44
//
// Write your own version of a simple desk calculator that can handle 
// binary operations.
// 

#include <iostream>
#include <functional>
#include <map>
#include <string>

int add (int lhs, int rhs) { return lhs + rhs; }
struct Div{ int operator()(int x, int y) { return x / y; } };
auto  mod = [](int lhs, int rhs) { return lhs % rhs; };

auto binops = std::map<std::string, std::function<int (int, int)>> {
        {"+", add},                                   // function pointer
        {"-", std::minus<int>()},                     // library functor
        {"*", [] (int x, int y) { return x * y; }},   // unnamed lambda
        {"/", Div()},                                 // user-dedined functor
        {"%", mod}                                    // named lambda object
    };

int main() {

    while (std::cout << "Please enter as: num operator num:\n", true) {
        int lhs, rhs; std::string op;
        std::cin >> lhs >> op >> rhs;
        std::cout << binops[op](lhs, rhs) << std::endl;
    }

    return 0;
}


// Exercise 5.24
//
// Revise your program to throw an exception if the second number is zero. 
// Test your program with a zero input to see what happens on your system 
// if you don’t catch an exception.
//

#include <iostream>
#include <stdexcept>

using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;

int main() {
    double num1, num2;
    cout << "Please enter two numbers: " << endl;
    cin >> num1 >> num2;
    if (num2 == 0) 
        throw runtime_error("The divisor can not be zero.");
    else 
        cout << "The result of " << num1 << "/" << num2 
         << " is " << num1/num2 << endl;
    return 0;
}
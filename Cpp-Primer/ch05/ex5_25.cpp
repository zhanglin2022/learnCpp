// Exercise 5.25
//
// Revise your program from the previous exercise to use a try block to catch 
// the exception. 
// The catch clause should print a message to the user and ask them to supply 
// a new number and repeat the code inside the try.
// 

#include <iostream>
#include <stdexcept>

using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;

int main() {
    for (double num1, num2; cout << "Input two numbers:\n ", cin >> num1 >> num2;) {
        try {
            if (num2 == 0) 
                throw runtime_error("The divisor can not be zero.");
            else 
                cout << "The result of " << num1 << "/" << num2 
                     << " is " << num1/num2 << endl;
        } catch (runtime_error err) {
            cout << err.what()
                 << "Try Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n') 
                break;
        }
    }
    return 0;
}
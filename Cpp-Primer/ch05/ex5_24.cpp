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
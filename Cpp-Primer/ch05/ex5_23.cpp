#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    double num1, num2;
    cout << "Please enter two numbers: " << endl;
    cin >> num1 >> num2;
    if (num2 == 0) 
        cout << "The divisor can not be zero." << endl;
    else 
        cout << "The result of " << num1 << "/" << num2 
         << " is " << num1/num2 << endl;
    return 0;
}
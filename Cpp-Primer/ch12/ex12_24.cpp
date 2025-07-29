#include <iostream>
#include <string>
#include <string.h>

using std::string; using std::cin; using std::cout; using std::endl;

int main() {
    cout << "How long do you want the string? ";
    int size = 0;
    cin >> size;
    char* input = new char[size + 1]();
    std::cin.ignore();
    cout << "Input the string: ";
    cin.get(input, size + 1);
    cout << input << endl;
    delete [] input;
    // Test: if longer than the array size, we will lost the characters which are out of range.

    return 0;
}
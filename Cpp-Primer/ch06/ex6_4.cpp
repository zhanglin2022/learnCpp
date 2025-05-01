#include <iostream>
#include <string>
#include <stdexcept>

using std::string;
using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;

int fact(int val) {
    return val > 1 ? val * fact(val - 1) : 1;
}

void interactive_face() {
    string const input = "Enter a number within [1, 13): \n";
    string const out_of_range = "Out of range, please try again. \n";
    for (int i; cout << input, cin >> i;) {
        if (i <1 || i > 12) {
            cout << out_of_range;
            continue;
        }
        cout << i << "! is " << fact(i) << endl;
    }
}

int main() {
    interactive_face();
    return 0;
}
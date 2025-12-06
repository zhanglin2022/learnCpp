// Exercise 3.1
// 
// Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76) with 
// appropriate using declarations.
//

#include <iostream>

using std::cout;
using std::endl;

int main() {
    // Rewrite 1.4.1 with using declarations.
    int sum = 0;
    for (int val = 1 ; val <= 10 ; ++val) sum += val;
    cout << "Sum of 1 to 10 inclusive is " << sum << endl;

    return 0;
}
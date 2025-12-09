// Exercise 7.27
//
// Add the move, set, and display operations to your version of Screen. 
// Test your class by executing the following code: 
// Screen myScreen(5, 5, ’X’); 
// myScreen.move(4,0).set(’#’).display(cout); 
// cout << "\n"; 
// myScreen.display(cout); 
// cout << "\n";
//

#include "ex7_27.h"
#include <iostream>

using std::cout;

int main() {
    Screen myScreen(5, 5, 'X'); 
    myScreen.move(4,0).set('#').display(cout); 
    cout << "\n"; 
    myScreen.display(cout); 
    cout << "\n";

    return 0;
}

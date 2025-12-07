// Exercise 3.40
//
// Write a program to define two character arrays initialized from string literals. 
// Now define a third character array to hold the concatenation of the two arrays. 
// Use strcpy and strcat to copy the two arrays into the third.
//

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

const char cs1[] = "Moon";
const char cs2[] = "Shadow";

int main() {
    constexpr size_t new_size = strlen(cs1) + strlen(" ") + strlen(cs2) + 1;
    char largeStr[new_size];

    strcpy(largeStr, cs1);
    strcat(largeStr, " ");
    strcat(largeStr, cs2);
    cout << "The concatetion of " << cs1 << " and " << cs2
         << " is " << largeStr << endl;
    return 0;
}
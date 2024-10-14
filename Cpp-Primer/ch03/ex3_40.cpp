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
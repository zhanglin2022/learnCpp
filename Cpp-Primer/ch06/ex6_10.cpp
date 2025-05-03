#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    for(int i, j; cout <<"Enter two numbers: \n", cin >> i >> j;) {
        swap(&i, &j);
        cout << i << " " << j << endl;
    }
    return 0;
}
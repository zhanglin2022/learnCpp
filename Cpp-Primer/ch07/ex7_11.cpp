#include <iostream>
#include "ex7_11.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    Sales_data item1;
    print(cout, item1) << endl;

    Sales_data item2("1111");
    print(cout, item2) << endl;

    Sales_data item3("2222", 3, 10.00);
    print(cout, item3) << endl;

    Sales_data item4(cin);
    print(cout, item4) << endl;

    return 0;
}
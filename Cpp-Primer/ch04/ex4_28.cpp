#include <iostream>

using std::cout;
using std::endl;

int main() {
    // void type
    cout << "nullptr_t: " << sizeof(nullptr_t) << " bytes" << endl << endl;

    // boolean type
    cout << "bool: " << sizeof(bool) << " bytes" << endl << endl;

    // character type
    cout << "char: " << sizeof(char) << " bytes" << endl;
    cout << "wchar_t: " << sizeof(wchar_t) << " bytes" << endl;
    cout << "char16_t: " << sizeof(char16_t) << " bytes" << endl;
    cout << "char32_t: " << sizeof(char32_t) << " bytes" << endl << endl;

    // integers type
    cout << "short: " << sizeof(short) << " bytes" << endl;
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "long: " << sizeof(long) << " bytes" << endl;
    cout << "long long: " << sizeof(long long) << " bytes" << endl << endl;
    
    // floating point type
    cout << "float: " << sizeof(float) << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "long double: " << sizeof(long double) << " bytes" << endl << endl;

    // fixed width integers
    cout << "int8_t: " << sizeof(int8_t) << " bytes" << endl;
    cout << "uint8_t: " << sizeof(uint8_t) << " bytes" << endl;
    cout << "int16_t: " << sizeof(int16_t) << " bytes" << endl;
    cout << "uint16_t: " << sizeof(uint16_t) << " bytes" << endl;
    cout << "int326_t: " << sizeof(int32_t) << " bytes" << endl;
    cout << "uint32_t: " << sizeof(uint32_t) << "bytes" << endl;
    cout << "int64_t: " << sizeof(int64_t) << " bytes" << endl;
    cout << "uint64_t: " << sizeof(uint64_t) << " bytes" << endl << endl;

    return 0;
}
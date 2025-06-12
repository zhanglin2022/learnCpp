#include <iostream>
#include <string>

using std::string; using std::cout; using std::endl;

int main() {
    string str("ab2c3d7R4E6");
    string nums("123456789");
    string apbts("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    // use find_first_of
    cout << "numeric characters: ";
    for (size_t pos = 0; (pos = str.find_first_of(nums, pos)) != string::npos;++pos)
        cout << str[pos] << " ";
    cout << "\nalphabetic characters: ";
    for (size_t pos = 0; (pos = str.find_first_of(apbts, pos)) != string::npos;++pos) 
        cout << str[pos] << " ";
    cout << endl;

    return 0;
}
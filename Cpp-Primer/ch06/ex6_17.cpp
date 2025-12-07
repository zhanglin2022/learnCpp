// Exercise 6.17
//
// Write a function to determine whether a string contains any capital letters. 
// Write a function to change a string to all lowercase. Do the parameters you 
// used in these functions have the same type? If so, why? If not, why not?
// 

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

bool any_capital(const string &str) {
    for(auto ch : str) 
        if (isupper(ch)) return true;
    return false;
}

void to_lowercase(string &str) {
    for(auto &ch : str) ch = tolower(ch);
}

int main() {
    string str("Philosophy");
    bool hasCapital = any_capital(str);
    to_lowercase(str);
    cout << "any captital letters: " << hasCapital << endl;
    cout << "to all lowercase: " << str << endl;

    return 0;
}
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
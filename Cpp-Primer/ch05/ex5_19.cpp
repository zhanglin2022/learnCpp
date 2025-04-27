#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {

    string rsp;
    do {
        cout << "Please enter two words: ";
        string s1, s2;
        cin >> s1 >> s2;
        cout << (s1.size() <= s2.size() ? s1 : s2) 
             << " is less than the other. \n\n" 
             << "More? Enter yes or no: ";
        cin >> rsp;

    } while (!rsp.empty() && rsp[0] != 'n');
    return 0;
}
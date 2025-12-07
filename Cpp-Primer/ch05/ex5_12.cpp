// Exercise 5.12
// 
// Modify our vowel-counting program so that it counts the number of occurrences 
// of the following two-character sequences: ff, fl, and fi.
//

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    char ch, prechar = '\0';
    unsigned aCnt=0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, 
    tabCnt = 0, newlineCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
    while(cin >> std::noskipws >> ch) {
        switch (ch) {
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
                if (prechar == 'f') ++fiCnt;
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlineCnt;
                break;
            case 'f':
                if (prechar == 'f') ++ffCnt;
                break;
            case 'l':
                if (prechar == 'f') ++flCnt;
                break;
        }
        prechar = ch;
    }
    cout << "Number of vowel a(A): \t" << aCnt << '\n'
         << "Number of vowel e(E): \t" << eCnt << '\n'
         << "Number of vowel i(I): \t" << iCnt << '\n'
         << "Number of vowel o(O): \t" << oCnt << '\n'
         << "Number of vowel u(U): \t" << uCnt << '\n'
         << "Number of vowel blank spaces: \t" << spaceCnt << '\n'
         << "Number of vowel tabs: \t" << tabCnt << '\n'
         << "Number of vowel newlines: \t" << newlineCnt << '\n'
         << "Number of ff: \t" << ffCnt<< '\n'
         << "Number of fl: \t" << flCnt<< '\n'
         << "Number of fi: \t" << fiCnt<< endl;

    return 0;
}

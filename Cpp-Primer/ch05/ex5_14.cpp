#include<iostream>
#include<string>

using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

int main() {
    pair<string, int> max_duplicated;
    unsigned cnt = 0;
    for(string str, prestr; cin >> str; prestr = str) {
        if (str == prestr) ++cnt;
        else cnt = 0;
        if (cnt > max_duplicated.second) max_duplicated = {prestr, cnt};
    }
    if (max_duplicated.first.empty()) cout << "No word was repeated." << endl;
    else cout << "The word " << max_duplicated.first << " occured " 
              << max_duplicated.second + 1 << " times." << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <fstream>

using std::string; using std::ifstream; using std::cout; using std::endl; using std::cerr;

int main() {
    ifstream ifs("../../data/phone.txt");
    string asde("bdfghjklpqty");
    string loggest;

    if (!ifs) return -1;
    for (string word; ifs >> word; ) {
        if (word.find_first_of(asde) != string::npos) {
            loggest = word.size() > loggest.size() ? word : loggest;
        }
    }
    cout << loggest << endl;
    
    return 0;
}
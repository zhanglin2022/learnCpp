#include <iostream>
#include <vector>
#include <string>

using std::vector; using std::string; using std::cin; using std::cout; using std::endl;

int main() {
    vector<string> svec;
    string word;
    auto iter = svec.begin();
    while (cin >> word)
        iter = svec.insert(iter, word);
        // svec.push_front(word); // error: std:: vector has no member "push_front"
    for (auto s : svec) cout << s << endl;

    return 0;
}
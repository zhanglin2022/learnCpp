#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    string lettergrade;
    for(int grade; cin >> grade;) {
        if (grade < 60)
            lettergrade = scores[0];
        else {
            lettergrade = scores[(grade - 50) / 10];
            if (grade != 100)
                lettergrade += grade % 10 > 7 ? "+" : grade % 10 < 3 ? "-" : "";
        }
        cout << lettergrade << endl;    
    }
    return 0;
}

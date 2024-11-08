#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

int main () {
    vector<int> grades = {99, 80, 72, 63, 55};
    for (auto grade : grades)
        cout << ((grade > 90) ? "high pass"
                              : (grade > 75) ? "low pass"
                              : (grade < 60) ? "fail" : "pass") << endl;
    return 0;
}
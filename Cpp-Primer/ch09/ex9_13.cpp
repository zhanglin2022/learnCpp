#include<iostream>
#include<list>
#include<vector>

using std::list; using std::vector; using std::cout; using std::endl;

int main() {
    list<int> ilst(5, 1);
    vector<int> ivec(5, 2);

    // from list<int> to vector<double>
    vector<double> dvec(ilst.begin(), ilst.end());
    for (const auto i : ilst) 
        cout << i << " ";
    cout << endl;
    for (const auto d : dvec) 
        cout << d << " ";
    cout << endl;

    // from vector<int> to vector<double>
    vector<double> dvec2(ivec.begin(), ivec.end());
    for (const auto i : ivec)
        cout << i << " ";
    cout << endl;
    for (const auto d : dvec2)
        cout << d << " ";
    cout << endl;

    return 0;
}
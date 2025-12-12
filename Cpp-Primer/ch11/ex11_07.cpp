// Exercise 11.7
//
// Define a map for which the key is the family’s last name and the value is 
// a vector of the children’s names. 
// Write code to add new families and to add new children to an existing family.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>

using std::vector; using std::string; using std::cin; using std::cout; using std::endl;

using Famliy = std::map<string, vector<string>>;

auto make_families() {
    Famliy families;
    for (string fn; cout << "last name: \n", cin >> fn;) {
        for (string cn; cout << "Children's name: \n", cin >> cn;)
            families[fn].push_back(cn);
    }
    return families;
}

void print(Famliy const& fam) {
    for (auto const& kv : fam) {
        cout << kv.first << ": ";
        for (auto const& chrid : kv.second) 
            cout << chrid << " ";
        cout << endl;
    }
}
int main() {
    print(make_families());
    return 0;
}
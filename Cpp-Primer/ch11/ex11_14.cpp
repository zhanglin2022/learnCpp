// Exercise 11.14
//
// Extend the map of children to their family name that you wrote for the 
// exercises in § 11.2.1 (p. 424) by having the vector store a pair that 
// holds a child’s name and birthday.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>

using std::vector; using std::string; using std::cin; using std::cout; using std::endl; using std::pair;

class Famlies {
public:
    using child = pair<string, string>;
    using children = vector<child>;
    using Data = std::map<string, children>;
    
    auto add (string const& fam, string const& chdNm, string const& chdBd) {
        _data[fam].emplace_back(chdNm, chdBd);
    }

    auto print() const {
        for (auto const& pair : _data) {
            cout << pair.first << ":\n";
            for (auto const& child : pair.second) 
                cout << child.first << " " << child.second << endl;
            cout << endl;
        }
    }

private:
    Data _data;
};

int main() {
    Famlies families;
    auto msg = "Please enter last name, first name and birthday:\n";
    for (string f, cn, bd; cout << msg, cin >> f >> cn >> bd; families.add(f, cn, bd));
    families.print();

    return 0;
}
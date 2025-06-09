#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::string; using std::vector; using std::list;

int main() {
    list<const char*> lst{"Sun", "Moon"};
    vector<string> svec;
    svec.assign(lst.cbegin(), lst.cend());
    for (auto &s : svec) 
        std::cout << s << std::endl;
    
    return 0;
}
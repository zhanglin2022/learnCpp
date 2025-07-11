#include <iostream>
#include <string>
#include <map>

using std::map; using std::string; using std::cout; using std::endl;

int main() {
    map<int, string> m = {{1, "aa"}, {2, "bb"}};
    using kt = map<int, string>::key_type;
    using mt = map<int, string>::mapped_type;
    
    return 0;
}
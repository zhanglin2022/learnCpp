// Exercise 11.26
// 
// What type can be used to subscript a map? What type does the subscript 
// operator return? 
// Give a concrete example—that is, define a map and then write the types 
// that can be used to subscript the map and the type that would be returned 
// from the subscript operator.
//

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
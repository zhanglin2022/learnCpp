// Exercise 11.23
//
// Rewrite the map that stored vectors of children’s names with a key 
// that is the family last name for the exercises in § 11.2.1 (p. 424) 
// to use a multimap.
//

#include <iostream>
#include <map>
#include <string>

using std::multimap; using std::string; using std::cin; using std::cout; using std::endl;

int main() {
	multimap<string, string> families;
	for (string fn, cn; cin >> fn >> cn; families.emplace(fn, cn));
	for (auto const& kv : families)
		cout << kv.second << " " << kv.first << endl;
	return 0;
}
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
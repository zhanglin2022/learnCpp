// Exercise 11.31
//
// Write a program that defines a multimap of authors and their works. 
// Use find to find an element in the multimap and erase that element. 
// Be sure your program works correctly if the element you look for is 
// not in the map.
//

#include <iostream>
#include <map>
#include <string>

using std::multimap; using std::string; using std::cout; using std::endl;

int main() {
    multimap<string, string> authors{
        {"Dostoevsky", "crime-and-punishment"},
        {"Dostoevsky", "the-brothers-karamazov"},
        {"Ayn Rand", "the-fountainhead"}};
    string author("Dostoevsky");
    string work("crime and punishment");
    auto found = authors.find(author);
    auto count = authors.count(author);
    while (count) {
        if (found->second == work) {
            authors.erase(found);
            break;
        }
        ++found;
        --count;
    }
    for (auto const& kv : authors)
        cout << kv.first << ": " << kv.second << endl;
    
    return 0;
}
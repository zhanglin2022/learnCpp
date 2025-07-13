#include <iostream>
#include <map>
#include <string>

using std::multimap; using std::string; using std::cout; using std::endl;

int main() {
    multimap<string, string> authors{
        {"Dostoevsky", "crime and punishment"},
        {"Dostoevsky", "the brothers karamazov"},
        {"Ayn Rand", "the fountainhead"}};
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
    
    for (auto const& kv : authors) {
        cout << kv.second << ", " << kv.first << endl;
    }

    return 0;
}
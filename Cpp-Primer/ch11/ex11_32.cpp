#include <iostream>
#include <map>
#include <string>
#include <set>

using std::multimap; using std::string; using std::cout; using std::endl;

int main() {
    multimap<string, string> authors{
        {"Dostoevsky", "crime-and-punishment"},
        {"Dostoevsky", "the-brothers-karamazov"},
        {"Ayn Rand", "the-fountainhead"}};
    std::map<string, std::multiset<string>> order_authors;
    for (const auto &author : authors)
        order_authors[author.first].insert(author.second);
    for (const auto &author : order_authors) {
        std::cout << author.first << ": ";
        for (const auto &work : author.second)
            std::cout << work << " ";
        std::cout << std::endl;
    }
    return 0;
}
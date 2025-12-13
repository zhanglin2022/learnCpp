// Exercise 12.33
// 
// In Chapter 15 we’ll extend our query system and will need some additional 
// members in the QueryResult class. 
// Add members named begin and end that return iterators into the set of line 
// numbers returned by a given query, and a member named get_file that returns 
// a shared_ptr to the file in the QueryResult object.
//

#include "ex12_33.h"
#include <iostream>

void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);
    do {
        std::cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    } while (true);
}

int main()
{
    std::ifstream file("../../data/give_to_transform.txt");
    runQueries(file);

    return 0;
}

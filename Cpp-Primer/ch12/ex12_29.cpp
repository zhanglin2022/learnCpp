// Exercise 12.29
// 
// We could have written the loop to manage the interaction with the user 
// as a do while (5.4.4, p. 189) loop. 
// Rewrite the loop to use a do while. Explain which version you prefer 
// and why.
//

#include "ex12_27_30.h"
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

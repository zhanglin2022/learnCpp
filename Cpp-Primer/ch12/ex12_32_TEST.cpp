#include "ex12_32.h"
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

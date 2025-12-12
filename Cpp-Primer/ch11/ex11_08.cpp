// Exercise 11.8
//
// Write a program that stores the excluded words in a vector instead of 
// in a set. What are the advantages to using a set?
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> exclude = { "aa", "bb", "cc", "dd", "ee", "ff" };
    for (std::string word; std::cout << "Enter please:\n", std::cin >> word; )
    {
        auto is_excluded = std::binary_search(exclude.cbegin(), exclude.cend(), word);
        auto reply = is_excluded ? "excluded" : "not excluded";
        std::cout << reply << std::endl;
    }
    return 0;
}

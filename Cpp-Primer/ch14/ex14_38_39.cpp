// Exercise 14.38 and Exercise 14.39
//
// Exercise 14.38: Write a class that tests whether the length of a given 
// string matches a given bound. 
// Use that object to write a program to report how many words in an input 
// file are of sizes 1 through 10 inclusive.
//
// Exercise 14.39: Revise the previous program to report the count of words 
// that are sizes 1 through 9 and 10 or more.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>

struct IsInRange {
    IsInRange(std::size_t lower, std::size_t upper): _lower(lower), _upper(upper) { }

    bool operator()(std::string const& str) const {
        return str.size() >= _lower && str.size() <= _upper;
    }

    std::size_t lower_bound() const {
        return _lower;
    }

    std::size_t upper_bound() const {
        return _upper;
    }

private:
    std::size_t _lower;
    std::size_t _upper;
};

int main() {
    // create predicates with various upper bounds
    std::size_t lower = 1;
    auto uppers = {3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u};
    std::vector<IsInRange> predicates;
    for (auto upper : uppers)
        predicates.push_back(IsInRange{lower, upper});

    // create count table to strore counts
    std::map<std::size_t, std::size_t> count_table;
    for (auto upper : uppers)
        count_table[upper] = 0;

    // read files and count
    std::ifstream ifs("../../data/phone.txt");
    for (std::string word; ifs >> word;)
        for(auto is_size_in_range : predicates)
            if (is_size_in_range(word))
                ++count_table[is_size_in_range.upper_bound()];

    // print
    for (auto pair: count_table)
        std::cout << "count in range [1, " << pair.first << "] : " << pair.second << std::endl;

    return 0;
}

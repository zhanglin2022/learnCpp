// Exercise 8.13
// 
// @brief ewrite the phone number program from this section to read from
//        a named file rather than from cin.'
// @see   ex8_11.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::vector;
using std::isdigit;
using std::cout;
using std::endl;
using std::cerr;

struct PersonInfo{
    string name;
    vector<string> phones;
};

bool valid(const string& str)
{
    return isdigit(str[0]);
}

string format(const string& str)
{
    return str.substr(0,3) + "-" + str.substr(3,3) + "-" + str.substr(6);
}

int main() {
    ifstream ifs("../../data/phone.txt");
    if (!ifs) {
        cerr << "No data?!" << std::endl;
        return -1;
    }

    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(ifs, line)) {
        PersonInfo info;
        record.clear();
        record.str(line);        
        record >> info.name;
        while (record >> word) 
            info.phones.push_back(word);
        people.push_back(info);
    } 

    for (const auto &entry : people) {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
            if (!valid(nums)) badNums << " " << nums;
            else formatted << " " << format(nums);
        if (badNums.str().empty())
            cout << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    } 

    return 0;
}

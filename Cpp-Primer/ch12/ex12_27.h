#ifndef EX12_27_H
#define EX12_27_H

#include <iostream>
#include <fstream>
#include <strstream>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <string>

using std::cin; using std::cout; using std::endl; using std::vector; 
using std::map; using std::set; using std::string; using std::shared_ptr; 
using std::istringstream; using std::ifstream;
class QueryResult;

class TextQuery { 
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    // TODO: which data should be share  and how to share?
    shared_ptr<vector<string>> file; 
    map<string, shared_ptr<set<line_no>>> word_line;
};












#endif
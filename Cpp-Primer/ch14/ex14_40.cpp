// Exercise 14.40
//
// Rewrite the biggies function from § 10.3.2 (p. 391) to use function-object 
// classes in place of lambdas.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string; using std::vector; using std::cout; using std::endl; 

struct IsShorter {
    bool operator()(const string &s1, const string &s2) const { return s1.size() < s2.size(); }
};

struct IsLongger {
    IsLongger(const size_t sz): sz_(sz) { }
    bool operator()(const string &str) const { return str.size() >= sz_; }
private:
    size_t sz_;
};

struct Print {
    void operator()(const string &str) const { cout << str << " "; }
};

string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr > 1) ? word + ending : word;
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words); 
    stable_sort(words.begin(), words.end(), IsShorter());
    auto wc = find_if(words.begin(), words.end(), IsLongger(sz));
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(), Print());
    cout << endl;
}

int main() {
    vector<string> svec{"fox", "jumps", "over", "quick", "red", "red", "slow", "the", "turtle"};
    biggies(svec, 4);

    return 0;
}

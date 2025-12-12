// Exercise 10.16
//
// Write your own version of the biggies function using lambdas.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector; using std::string; using std::cout; using std::endl;

void elimDups(vector<string> &words) {
    std::sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

// return the pural verison of word if ctr is greater than 1
string make_plural (size_t ctr, const string &word, const string &ending = "s") {
    return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words); 
    // sort wordsby size, but maintain alphabetical order for words of the same size
    std::stable_sort(words.begin(), words.end(), [] (const string &a, const string &b) 
                { return a.size() < b.size(); });
    // get an iterator to the first element whose size()is >=sz
    auto wc = find_if(words.begin(), words.end(), [sz] (const string &a) 
                        { return a.size() >= sz; });
    // compute the number of elements with size >= sz
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer " << endl;
    // print biggies
    std::for_each(wc, words.end(), [] (const string &s){ cout << s << " ";} ); 
    cout << endl;
}

int main() {
    vector<string> svec{"aaaa", "aaaaa", "333", "666666"};
    biggies(svec, 5);

    return 0;
}
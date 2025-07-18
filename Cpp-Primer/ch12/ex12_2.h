#ifndef EX12_2_H
#define EX12_2_H

#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
#include <exception>

using std::vector; using std::string; using std::make_shared;

class StrBlob {
public:
    using size_type = vector<string>::size_type;

    StrBlob(): data(make_shared<vector<string>>()) {}
    StrBlob(std::initializer_list<string> il): data(make_shared<vector<string>>(il)) {}

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &t) { data->push_back(t); }
    void pop_back();

    string& front();
    string& back();
    const string& front() const;
    const string& back() const;

private:
    std::shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size()) throw std::out_of_range(msg);
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

string& StrBlob::front() { 
    check(0, "front on empty StrBlob"); 
    return data->front(); 
} 

string& StrBlob::back() { 
    check(0, "back on empty StrBlob"); 
    return data->back(); 
}

const string& StrBlob::front() const {
    check(0, "front on empty StrBlob"); 
    return data->front();
}

const string& StrBlob::back() const {
    check(0, "back on empty StrBlob"); 
    return data->back(); 
}

#endif
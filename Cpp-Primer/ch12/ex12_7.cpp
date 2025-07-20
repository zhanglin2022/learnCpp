#include <iostream>
#include <memory>
#include <vector>

using std::shared_ptr; using std::vector; using std::cin; using std::cout; using std::endl;
using Sptr = std::shared_ptr<vector<int>>;

auto returnSptVec() {
    return std::make_shared<vector<int>>();
}

auto assign(Sptr vec) {
    for (int i; cout <<"Pls Enter:\n", cin >> i; vec->push_back(i));
    return vec;
}

std::ostream& print(Sptr vec) {
    for (const auto i : *vec) cout << i << " ";
    return cout;
}

int main() {
    auto vec = assign(returnSptVec());
    print(vec) << endl;

    return 0;
}
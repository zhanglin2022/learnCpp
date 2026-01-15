// Exercise 13.58
//
// @see Exercise 13.56 and Exercise 13.57
//
// Write versions of class Foo with print statements in their sorted
// functions to test your answers to the previous two exercises.
//

#include <iostream>
#include <algorithm>
#include <vector>

class Foo {
public:
    Foo sorted() &&;
    Foo sorted() const &;
private:
    std::vector<int> data;
};

Foo Foo::sorted() && {
    std::sort(data.begin(), data.end());
    std::cout << "&&" << std::endl;    // debug
    return *this;
}

Foo Foo::sorted() const & {
    // Foo ret(*this);
    // sort(ret.data.begin(), ret.data.end());
    // return ret;

    std::cout << "const &" << std::endl;    // debug

    // Foo ret(*this);
    // return ret.sorted();    // Exercise 13.56

    return Foo(*this).sorted();    // Exercise 13.57
}

int main() {
    Foo().sorted();    // call "&&"
    Foo f;
    f.sorted();    // call "const &"
    
    return 0;
}

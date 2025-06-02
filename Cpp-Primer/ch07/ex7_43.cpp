#include <vector>

class NoDefault {
public:
    NoDefault(int i) { }
};

class C {
public: 
    C(): def(0) { } // the Default Constructor of C.
private:
    NoDefault def;
};

int main() {
    C c;
    std::vector<C> vec(10);
    // std::vector<NoDefault> vec1(10); // error: no matching function for call to ‘NoDefault::NoDefault()’

    return 0;
}

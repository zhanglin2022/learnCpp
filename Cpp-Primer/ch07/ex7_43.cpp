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

    return 0;
}

#include <iostream>
#include <memory>

using std::cout; using std::endl; using std::shared_ptr;

void process(shared_ptr<int> ptr) {
    cout << "inside the process function: " << ptr.use_count() << endl;
}

int main() {
    auto sp = std::make_shared<int>();
    auto p = sp.get();
    delete p;

    return 0;
}
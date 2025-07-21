#include <iostream>
#include <memory>

using std::cout; using std::endl; using std::shared_ptr;

void process(shared_ptr<int> ptr) {
    cout << "inside the process function: " << ptr.use_count() << endl;
}

int main() {
    shared_ptr<int> p(new int(42));
    process(shared_ptr<int>(p));

    // codes below shows how the reference count change
    cout << p.use_count() << endl;
    auto q = p;
    cout << p.use_count() << endl;
    cout << "the int p now points to is: " << *p << endl;

    return 0;
}
// Exercise 12.11
//
// What would happen if we called process as follows? 
// process(shared_ptr<int>(p.get()));
//

#include <iostream>
#include <memory>

using std::cout; using std::endl; using std::shared_ptr;

void process(shared_ptr<int> ptr) {
    cout << "inside the process function: " << ptr.use_count() << endl;
}

int main() {
    shared_ptr<int> p(new int(42));
    /**
     * @brief   std::shared_ptr<int>(p.get()) construct a temporary shared_ptr and copy it
     *          to the parameter. However it is not a copy of p. As a result, at end of this
     *          main function p will free the memory that has been freed inside process ().
     *          That's why "double free" was generated.
     */
    process(shared_ptr<int>(p.get()));

    return 0;
}
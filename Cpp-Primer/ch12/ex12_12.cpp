// Exercise 12.12
//
// Using the declarations of p and sp explain each of the following calls 
// to process. If the call is legal, explain what it does. If the call is 
// illegal, explain why: 
// 
// auto p = new int(); 
// auto sp = make_shared<int>(); 
// (a) process(sp); 
// (b) process(new int()); 
// (c) process(p); 
// (d) process(shared_ptr<int>(p));
//

#include <iostream>
#include <memory>

using std::cout; using std::endl; using std::shared_ptr;

void process(shared_ptr<int> ptr) {
    cout << "inside the process function: " << ptr.use_count() << endl;
}

int main() {
    auto p = new int();
    auto sp = std::make_shared<int> ();

    /** @brief
     *  legal. just copy sp to process.
    */
   process(sp);
   
    /** @brief
     *  illegal. plain pointer cannot convert to smart pointer implicitly.
    */
   // process(new int());
   
   /** @brief
     *  illegal. plain pointer cannot convert to smart pointer implicitly.
    */
   // process(p);

    /** @brief
     *  legal. Butut it's a bad practice. 
     *  Because using smart pointer with raw pointer may 
     *  cause problems such as double free.
    */
    // process(shared_ptr<int>(p));
    
    return 0;
}
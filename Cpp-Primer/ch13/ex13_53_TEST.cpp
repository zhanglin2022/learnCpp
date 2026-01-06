// Exercise 13.53
//
// @see ex13_31.h
//
// As a matter of low-level efficiency, the HasPtr assignment operator is 
// not ideal. Explain why. 
// Implement a copy-assignment and move-assignment operator for HasPtr and 
// compare the operations executed in your new move-assignment operator 
// versus the copy-and-swap version.
//

#include "ex13_53.h"

int main() {
    HasPtr h1("Hello"), h2("world"), *pH = new HasPtr("good");
    h1 = h2;
    h1 = std::move(*pH);
    delete pH;
    
    return 0;
}

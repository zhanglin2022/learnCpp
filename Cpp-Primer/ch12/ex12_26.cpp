// Exercise 12.26
//
// Rewrite the program on page 481 using an allocator.
//

#include <iostream>
#include <memory>
#include <string>

using std::allocator; using std::string; using std::cin;

void input_string_reverse(size_t n) {
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    auto q = p;
    for (string str; cin>>str && q != p + n; )
        alloc.construct(q++, str);
    while (q != p) {
        std::cout << *--q << " ";
        alloc.destroy(q);
    }
    alloc.deallocate(p, n);
}

int main() {
    input_string_reverse(10);
    std::cout << std::endl;
    return 0;
}
// Exercise 15.6
//
// Test your print_total function from the exercises in § 15.2.1 (p. 595)
// by passing both Quote and Bulk_quote objects o that function.
//

#include "quote.h"
#include "bulk_quote.h"

int main() {
    Quote base("1234", 24.5);
    Bulk_quote derive("5678", 24.5, 5, 0.2);
    print_total(std::cout, base, 5);
    print_total(std::cout, derive, 5);
    return 0;
}

#include "Quote.h"
#include "Bulk_quote.h"

int main() {
    Quote base("1234", 24.5);
    Bulk_quote derive("5678", 24.5, 5, 0.2);
    print_total(std::cout, base, 5);
    print_total(std::cout, derive, 5);
    return 0;
}

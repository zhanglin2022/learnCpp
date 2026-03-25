#include "quote.h"

int main() {
    Quote book("1234", 25.5);
    print_total(std::cout, book, 5);
    return 0;
}

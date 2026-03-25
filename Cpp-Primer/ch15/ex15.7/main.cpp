#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

int main() {
    Quote q("12", 24.5);
    Bulk_quote bq("34", 24.5, 5, 0.2);
    Limit_quote lq("56", 24.5, 5, 0.2);
    print_total(std::cout, q, 10);
    print_total(std::cout, bq, 10);
    print_total(std::cout, lq, 10);
    return 0;
}

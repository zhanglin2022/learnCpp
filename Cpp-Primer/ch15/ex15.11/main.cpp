#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

void print_debug(const Quote &q) {
    q.debug();
}

int main() {
    Quote q("12", 24.5);
    Bulk_quote bq("34", 24.5, 5, 0.2);
    Limit_quote lq("56", 24.5, 5, 0.2);

    // not dynamic binding
    q.debug();  
    std::cout << std::endl;
    bq.debug(); 
    std::cout << std::endl;
    lq.debug(); 
    std::cout << "\n\n";

    // dynamic binding
    print_debug(q);
    std::cout << std::endl;
    print_debug(bq);
    std::cout << std::endl;
    print_debug(lq);
    std::cout << std::endl;

    return 0;
}

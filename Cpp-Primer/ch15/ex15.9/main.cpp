#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

int main() {
    Bulk_quote bulk_quote("bulk_quote_1", 24.5, 5, 0.2);
    
    // Differ: The pointer is of static type Quote, but it's dynamic type is Bulk 
    // Quote Because of polymorphism the Bulk Quote implementation of the net_price()
    // method gets called.
    Quote *quote_pointer = &bulk_quote;
    quote_pointer->net_price(5);

    // Differ: The reference is of static type Quote, but it's dynamic type is Bulk 
    // Quote Like with the pointer, the Bulk Quote implementation of the net_price()
    // method gets called.
    Quote &quote_reference = bulk_quote;
    quote_reference.net_price(5);

    // Differ: The static type of the second parameter `item` in `print_total` is `Quote&`, 
    // but when `bulk_quote` is passed, its dynamic type becomes `Bulk_quote`.
    print_total(std::cout, bulk_quote, 5);

    // Same: The static type of this variable is Quote. The Quote part of bulk_quote 
    // gets copied into quote, but the rest is not handled. The Quote implementation 
    // of the net_price() method gets called.
    Quote quote = bulk_quote;
    quote.net_price(5);
    
    return 0;
}

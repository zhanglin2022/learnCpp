#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"
#include "basket.h"
#include <vector>

int main() {
    Basket basket;

    for (unsigned i = 0; i != 10; ++i)
        basket.add_item(Bulk_quote("Bible", 20.6, 20, 0.3));

    for (unsigned i = 0; i != 10; ++i)
        basket.add_item(Bulk_quote("C++Primer", 30.9, 5, 0.4));

    for (unsigned i = 0; i != 10; ++i)
        basket.add_item(Quote("CLRS", 40.1));

    basket.total_receipt(std::cout);
    /**
     * ISBN: Bible # sold: 10 total due: 206
     * ISBN: C++Primer # sold: 10 total due: 185.4
     * ISBN: CLRS # sold: 10 total due: 401
     * Total Sale: 792.4
     */
    return 0;
}

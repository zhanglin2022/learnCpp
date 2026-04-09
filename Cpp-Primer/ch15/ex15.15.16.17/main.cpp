#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"

int main() {
    /*
    error: cannot declare variable ‘d’ to be of abstract type ‘Disc_quote’:
        Disc_quote d;

    note: because the following virtual functions are pure within ‘Disc_quote’:
        class Disc_quote: public Quote

    note: ‘virtual double Disc_quote::net_price(std::size_t) const’:
        virtual double net_price(std::size_t) const override = 0;
    */
    Disc_quote d;

    return 0;
}

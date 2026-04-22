#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"

int main() {
    Bulk_quote bq1; 
    Bulk_quote bq2("1234", 10.8, 10, 0.2);
    bq1 = std::move(bq2);
    /**
     * Quote default constructor 
     * Disc_quote default constructor
     * Bulk_quote default constructor
     * Quote 2 parameters constructor 
     * Disc_quote 4 parameters constructor
     * Bulk_quote 4 parameters constructor
     * Quote move assignment
     * Disc_quote move assignment
     * Bulk_quote move assignment
     * Bulk_quote destructor
     * Disc_quote destructor
     * Quote destructor
     * Bulk_quote destructor
     * Disc_quote destructor
     * Quote destructor
     */
    return 0;
}

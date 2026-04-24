#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"
#include <vector>

int main() {
    /**
     * @brief ex15.28    outcome == 9090
     */
    std::vector<Quote> vec;
    double total = 0.0;

    for (unsigned i = 1; i != 10; ++i)
        vec.push_back(Bulk_quote("cc", i * 10.1, 10, 0.3));
    
    for (auto &v : vec)
        total += v.net_price(20);
    
    std::cout << total << std::endl;
    std::cout << "======================\n\n";

    return 0;
}

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"
#include <vector>
#include <memory>

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

    /**
     * @brief ex15.29    outcome == 6363
     */

    std::vector<std::shared_ptr<Quote>> pvec;
    double total_p = 0.0;
    for (unsigned i = 1; i != 10; ++i)
        pvec.push_back(std::make_shared<Bulk_quote>(Bulk_quote("cc", i * 10.1, 10, 0.3)));

    for (auto &p : pvec)
        total_p += p->net_price(20);
    std::cout << total_p << std::endl;

    return 0;
}

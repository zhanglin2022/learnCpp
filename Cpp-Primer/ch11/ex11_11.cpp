#include "../ch07/ex7_26.h"
#include <set>

bool less (const Sales_data &lhs, const Sales_data &rhs) { 
    return lhs.isbn() < rhs.isbn(); 
}

int main() {
    using Less = bool (*) (Sales_data const&, Sales_data const&);
    std::multiset<Sales_data, Less> bookstore(less);

    return 0;
}

#include <iostream>

#include "query.h"
#include "andquery.h"
#include "orquery.h"

int main() {
    // exercise 15.36
    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout << q << std::endl;

    return 0;
}

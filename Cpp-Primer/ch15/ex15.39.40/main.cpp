#include <iostream>

#include "query.h"
#include "andquery.h"
#include "orquery.h"
#include "queryresult.h"

int main() {
    std::ifstream file("../ex15.39.40/test.txt");
    TextQuery tQuery(file);

    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout << q.eval(tQuery);

    return 0;
}

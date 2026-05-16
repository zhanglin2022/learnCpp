#include <iostream>

#include "queryhistory.h"
#include "query.h"
#include "andquery.h"
#include "orquery.h"
#include "queryresult.h"

int main() {
    std::ifstream file("../ex15.42_b/test.txt");
    TextQuery tQuery(file);
    QueryHistory history;
    Query q0("Alice");
    Query q1("hair");
    Query q2("Daddy");

    history.add_query(q0);
    history.add_query(q1);
    history[0] = history[0] | q2;

    auto result = history[0].eval(tQuery);
    std::cout << result;
    
    return 0;
}

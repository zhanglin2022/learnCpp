#include "bd_textquery.h"
#include "bd_queryresult.h"

int main() {
    std::ifstream file("../ex16.21.22/test.txt");
    TextQuery tQuery(file);
    auto result = tQuery.query("Alice");
    std::cout << result;
    
    return 0;
}
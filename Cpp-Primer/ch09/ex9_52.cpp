#include <iostream>
#include <stack>
#include <string>

using std::stack; using std::string; using std::cout; using std::endl;

int main () {
    string expression("Sun and (Moon)");
    bool bSee = false;
    stack<char> stk;

    for (const auto &e : expression) {
        if (e == '(') { bSee = true; continue; }
        else if (e == ')') bSee = false;

        if (bSee) stk.push(e);
    }
    
    string repstr;
    while (!stk.empty()) {
        repstr += stk.top();
        stk.pop();
    }

    expression.replace(expression.find('(')+1, repstr.size(), repstr);
    cout << expression << endl;

    return 0;
}
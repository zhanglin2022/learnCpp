// Exdercsie 9.52
// 
// Use a stack to process parenthesized expressions. When you see an open 
// parenthesis, note that it was seen. When you see a close parenthesis 
// after an open parenthesis, pop elements down to and including the open 
// parenthesis off the stack. 
// push a value onto the stack to indicate that a parenthesized expression 
// was replaced.
//

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
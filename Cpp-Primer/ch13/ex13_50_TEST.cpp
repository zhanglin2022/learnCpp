// Exercise 13.50
//
// @see ex13.48.cpp
//
// Put print statements in the move operations in your String class and
// rerun the program from exercise 13.48 in § 13.6.1 (p. 534) that used 
// a vector<String> to see when the copies are avoided.
//

#include "ex13_50_String.h"
#include <vector>
#include <iostream>

// Test reference to http://coolshell.cn/articles/10478.html

void foo(String x) {
    std::cout << x.c_str() << std::endl;
}

void bar(const String& x) {
    std::cout << x.c_str() << std::endl;
}

String baz() {
    String ret("world");
    return ret;
}

int main() {
    char text[] = "world";

    String s0;
    String s1("hello");
    String s2(s0);
    String s3 = s1;
    String s4(text);
    s2 = s1;

    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    String s5 = baz();

    std::vector<String> svec;
    svec.reserve(8);
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(s5);
    svec.push_back(baz());
    svec.push_back("good job");

    for (const auto &s : svec) {
        std::cout << s.c_str() << std::endl;
    }
    
    return 0;
}


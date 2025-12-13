// Exercise 12.23
//
// Write a program to concatenate two string literals, putting the result 
// in a dynamically allocated array of char. 
// Write a program to concatenate two library strings that have the same 
// value as the literals used in the first program.
//

#include <iostream>
#include <string>
#include <string.h>

int main() {
    // dynamaically allocated array of char
    char *concate_string = new char[strlen("hello " "word")+1];
    strcat(concate_string, "hello ");
    strcat(concate_string, "world");
    std::cout << concate_string << std::endl;
    delete []concate_string;

    // std::string
    std::string s1{"hello "}, s2{"world"};
    std::cout << s1 + s2 << std::endl;

    return 0;
}
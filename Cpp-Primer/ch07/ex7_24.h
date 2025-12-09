// Exercise 7.24
//
// Give your Screen class three constructors: a default constructor; 
// a constructor that takes values for height and width and initializes 
// the contents to hold the given number of blanks; 
// and a constructor that takes values for height, width, and a character 
// to use as the contents of the screen.
//

#ifndef EX7_24_H
#define EX7_24_H

#include <string>

class Screen {
public:
    typedef std::string::size_type pos;

    Screen() = default; // 1
    Screen(pos ht, pos wd): height(ht), width(wd),contents(ht * wd, ' ') { } // 2
    Screen(pos ht, pos wd, char c): height(ht), width(wd),contents(ht * wd, c) { } // 3
    
    char get() const { return contents[cursor]; }
    inline char get(pos r, pos c) const { return contents[r * width + c]; };

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

#endif
// Exercise 7.29
//
// Revise your Screen class so that move, set, and display functions return 
// Screen and check your prediction from the previous exercise. 
//

#ifndef EX7_29_H
#define EX7_29_H

#include <iostream>
#include <string>

class Screen {
public:
    typedef std::string::size_type pos;

    Screen() = default; // 1
    Screen(pos ht, pos wd): height(ht), width(wd),contents(ht * wd, ' ') { } // 2
    Screen(pos ht, pos wd, char c): height(ht), width(wd),contents(ht * wd, c) { } // 3
    
    char get() const { return contents[cursor]; }
    inline char get(pos r, pos c) const { return contents[r * width + c]; };
    Screen move(pos r, pos c);
    Screen set(char c);
    
    Screen display(std::ostream &os) { do_display(os); return *this; }
    const Screen display(std::ostream &os) const { do_display(os); return *this; }

private:
    void do_display(std::ostream &os) const {os << contents;}
    
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline Screen Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

inline Screen Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

#endif
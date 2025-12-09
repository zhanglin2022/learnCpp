// Exercise 7.27
//
// Add the move, set, and display operations to your version of Screen. 
// Test your class by executing the following code: 
// Screen myScreen(5, 5, ’X’); 
// myScreen.move(4,0).set(’#’).display(cout); 
// cout << "\n"; 
// myScreen.display(cout); 
// cout << "\n";
//

#ifndef EX7_27_H
#define EX7_27_H

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
    Screen &move(pos r, pos c);
    Screen &set(char c);
    
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }

private:
    void do_display(std::ostream &os) const {os << contents;}
    
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline Screen &Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

#endif
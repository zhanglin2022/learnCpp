// Exercise 13.34, Exercise 13.36 and Exercise 13.37
//
// Exercise 13.34: Write the Message class as described in this section.
// Exercise 13.36: Design and implement the corresponding Folder class. That class
//                 should hold a set that points to the Messages in that Folder.            
// Exercise 13.37: Add members to the Message class to insert or remove a given 
//                 Folder* into folders. These members are analogous to Folder’s 
//                 addMsg and remMsg operations.              

#ifndef EX13_34_36_37_H
#define EX13_34_36_37_H

#include <iostream>
#include <string>
#include <set>

using std::string; using std::set;

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    explicit Message(const string &str = ""): contents(str) { }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();

    void save(Folder&);
    void remove(Folder&);

    void print_debug();

private:
    string contents;
    set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders();

    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); };
};

void swap(Message&, Message&);

class Folder {
    friend class Message;
    friend void swap(Folder&, Folder&);
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();

    void print_debug();

private:
    set<Message*> msgs;
    
    void add_to_Message(const Folder&);
    void remove_from_Message();

    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
};

void swap(Folder&, Folder&);

#endif

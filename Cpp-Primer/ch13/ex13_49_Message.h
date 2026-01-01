// Exercise 13.49
//
// @see ex13_34_36_37.h
//
// Add a move constructor and move-assignment operator to your StrVec, 
// String, and Message classes.
// 

#ifndef EX13_49_MESSAGE_H
#define EX13_49_MESSAGE_H

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
    Message(Message&&); // need to update the Folders
    Message& operator=(Message&&); // need to update the Folders
    ~Message();

    void save(Folder&);
    void remove(Folder&);

    void print_debug();

private:
    void add_to_Folders(const Message&);
    void remove_from_Folders();

    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); };

    void move_folders(Message*);

private:
    string contents;
    set<Folder*> folders;
};

void swap(Message&, Message&);

class Folder {
    friend class Message;
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
public:
    explicit Folder(const std::string &str = "") :name(str) { }
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    Folder(Folder&&); // need to update the Messages
    Folder& operator=(Folder&&); // need to update the Messages
    ~Folder();

    const std::string& fldr() const { return name; }
    void print_debug();

private: 
    void add_to_Message(const Folder&);
    void remove_from_Message();

    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }

    void move_Messages(Folder*);

private:
    std::string name;
    set<Message*> msgs;
};

void swap(Folder&, Folder&);

#endif
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

#include <string>
#include <set>

using std::string; using std::set;

class Folder;

class Message {
    friend class Folder;
public:
    Message(const string &str = ""): contents(str) { }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();

    void save(Folder&);
    void remove(Folder&);

private:
    string contents;
    set<Folder*> folders;

    // utility functions used by copy constructor, assignment, and destructor
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
    for (auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders() {
    for (auto f : folders)
        f->remMsg(this);
    folders.clear();
}

Message::Message(const Message &m) :contents(m.contents), folders(m.folders) {
    add_to_Folders(m);
}

Message& Message::operator=(const Message &rhs) {
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::~Message() {
    remove_from_Folders();
}

class Folder {
public:
    void addMsg(const Message*);
    void remMsg(const Message*);

private:
    set<Message*> messages;
};









#endif
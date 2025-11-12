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

void Message::save(Folder &f) {
    addFldr(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    remFldr(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
    for (auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message &m) :contents(m.contents), folders(m.folders) {
    add_to_Folders(m);
}

void Message::remove_from_Folders() {
    for (auto f : folders)
        f->remMsg(this);
    // The book added one line here: folders.clear(); but I think it is redundant and more importantly, it will cause a bug:
    // - In Message::operator=, in the case of self-assignment, it first calls remove_from_Folders() and its folders.clear() 
    //   clears the data member of lhs(rhs), and there is no way we can assign it back to lhs.
    //   Refer to: http://stackoverflow.com/questions/29308115/protection-again-self-assignment
    // - Why is it redundant? As its analogous function Message::add_to_Folders(), Message::remove_from_Folders() should ONLY
    //   take care of the bookkeeping in Folders but not touch the Message's own data members - makes it much clearer and easier
    //   to use. As you can see in the 2 places where we call Message::remove_from_Folders(): in Message::operator=, folders.clear()
    //   introduces a bug as illustrated above; in the destructor ~Message(), the member "folders" will be destroyed anyways, why do
    //   we need to clear it first?
}

Message::~Message() {
    remove_from_Folders();
}

Message& Message::operator=(const Message &rhs) {
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void Message::print_debug() {
    std::cout << contents << std::endl;
}

class Folder {
    friend class Message;
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();

    void print_debug();

private:
    set<Message*> messages;
    
    void add_to_message(const Folder&);
    void remove_from_message();

    void addMsg(Message *m) { messages.insert(m); }
    void remMsg(Message *m) { messages.erase(m); }
};

void Folder::add_to_message(const Folder &f) {
    for (auto m : f.messages)
        m->addFldr(this);
}

Folder::Folder(const Folder &f): messages(f.messages) {
    add_to_message(f);
}

void Folder::remove_from_message() {
    for (auto m : messages)
        m->remFldr(this);
}

Folder::~Folder() {
    remove_from_message();
}

Folder& Folder::operator=(const Folder &rhs) {
    remove_from_message();
    messages = rhs.messages;
    add_to_message(rhs);
    return *this;
}

void Folder::print_debug() {
    for (auto m : messages)
        std::cout << m->contents << " ";
    std::cout << std::endl;
}

#endif

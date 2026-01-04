// Exercise 13.49
//
// @see ex13_34_36_37.cpp
//
// Add a move constructor and move-assignment operator to your StrVec, 
// String, and Message classes.
// 

#include "ex13_49_Message.h"
#include <iostream>

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    lhs.remove_from_Folders();
    rhs.remove_from_Folders();

    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);

    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}

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

//move the Folder pointers from m to this Message
void Message::move_folders(Message *m) {
    folders = std::move(m->folders);
    for (auto f : folders) {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();               
}

Message::Message(Message &&m) :contents(std::move(m.contents)) {
    move_folders(&m);
}

Message& Message::operator=(Message &&rhs) {
    if (this != &rhs) {
        remove_from_Folders();
        contents = rhs.contents;
        folders = std::move(rhs.folders);
        move_folders(&rhs);
    }
    return *this;
}

void Message::print_debug() {
    std::cout << contents << std::endl;
}

// Folder Implementation

void swap(Folder &lhs, Folder &rhs) {
    using std::swap;
    lhs.remove_from_Message();
    rhs.remove_from_Message();

    swap(lhs.msgs, rhs.msgs);

    lhs.add_to_Message(lhs);
    rhs.add_to_Message(rhs);
}

void Folder::add_to_Message(const Folder &f) {
    for (auto m : f.msgs)
        m->addFldr(this);
}

Folder::Folder(const Folder &f): name(f.name), msgs(f.msgs) {
    add_to_Message(f);
}

void Folder::remove_from_Message() {
    for (auto m : msgs)
        m->remFldr(this);
}

Folder::~Folder() {
    remove_from_Message();
}

Folder& Folder::operator=(const Folder &rhs) {
    remove_from_Message();
    name = rhs.name;
    msgs = rhs.msgs;
    add_to_Message(rhs);
    return *this;
}

void Folder::print_debug() {
    for (auto m : msgs)
        std::cout << m->contents << " ";
    std::cout << std::endl;
}

void Folder::move_Messages(Folder *f)
{
	msgs = std::move(f->msgs);
	for (auto m : msgs) {
		m->remFldr(f);
		m->addFldr(this);
	}
	f->msgs.clear();
}

Folder::Folder(Folder&& f) : name(std::move(f.name)) {
	move_Messages(&f);
}

Folder& Folder::operator=(Folder &&rhs) {
    if (this != &rhs) {
		remove_from_Message();
		name = std::move(rhs.name);
		move_Messages(&rhs);
	}
	return *this;
}

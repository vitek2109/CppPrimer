#include "Messaging.h"
#ifdef DEBUG
int main() { }
#endif

// -------------------------Message implementation-------------------------
// copy control
Message::Message(const Message &m) : 
    contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}
Message::Message(Message &&m) : contents(std::move(m.contents))
{
    move_Folders(&m);
}
Message& Message::operator= (const Message &rhs)
{
    remove_from_Folders();      // remove this message from all folders
    contents = rhs.contents;    // copy everything over from rhs
    folders = rhs.folders;
    add_to_Folders(rhs);        // add this message to all of it's new folders
    return *this;
}
Message& Message::operator=(Message &&rhs)
{
    if (this != &rhs) {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}
Message::~Message()
{
    remove_from_Folders();
}
// add/delete this message to/from a set of messages of the folder
void Message::save(Folder &f)
{
    folders.insert(&f); // add f to folders
    f.addMsg(*this);     // add this message to f's set
}
void Message::remove(Folder &f)
{
    folders.erase(&f);  // remove f from folders
    f.remMsg(*this);     // remove this message form f's set
}
// private functions
// add this message to all folders of some other message
void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)    // for every folder containing m
        f->addMsg(*this);        // add this message to it
}
// remove this message from all folders
void Message::remove_from_Folders()
{
    for (auto f : folders)  // for every folder
        f->remMsg(*this);    // remove this message
}
void Message::move_Folders(Message *m)
{
    folders = std::move(m.folders);
    for (auto f : folders) {
        f.remMsg(m);
        f.addMsg(this);
    }
    m->folders.clear();
}
// swap
void swap(Message &lhs, Message &rhs)
{
    using std::swap;                    // unnecessary, but a good habit
    lhs.remove_from_Folders();          // remove all pointers to these messages
    rhs.remove_from_Folders();
    swap(lhs.contents, rhs.contents);   // swap everything
    swap(lhs.folders, rhs.folders);
    lhs.add_to_Folders(lhs);            // add pointers from all the new folders
    rhs.add_to_Folders(rhs);
}

// -------------------------Folder implementation-------------------------
// copy control
Folder::Folder(const Folder &f) : messages(f.messages)
{
    add_to_Messages(f);
}
Folder& Folder::operator= (const Folder &rhs)
{
    remove_from_Messages();     // remove all pointers to this folder
    messages = rhs.messages;    // copy everything
    add_to_Messages(rhs);          // add this folder to all of it's new messages
    return *this;
}
Folder::~Folder()
{
    remove_from_Messages();
}
// message manipulation
Folder::addMsg(Message &m)
{
    messages.insert(&m);
    m.save(*this);
}
Folder::remMsg(Message &m)
{
    messages.erase(&m);
    m.remove(*this);
}
// private functions
// add all messages from other folder
void Folder::add_to_Messages(const Folder &f)
{
    for (auto m : f.messages)
        m->save(*this);
}
//remove all messages
void Folder::remove_from_Messages()
{
    for (auto m : messages)
        m->remove(*this);
}
// swap
void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;                    // unnecessary, but a good habit
    lhs.remove_from_Messages();          // remove all pointers to these folders
    rhs.remove_from_Messages();
    swap(lhs.messages, rhs.messages);   // swap everything
    lhs.add_to_Messages(lhs);           // add pointers from all the new messages
    rhs.add_to_Messages(rhs);
}

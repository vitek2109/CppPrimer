#ifndef MESSAGING
#define MESSAGING
#include <string>
#include <set>
#include <utility>

class Folder;

class Message {
    friend class Folder;
    friend void swap (Message&, Message&);
public:
    // folders implicitly initializes as an empty set 
    explicit Message(const std::string &s = "") : contents(s) {}
    // copy control
    Message(const Message&);                // copy constructor
    Message(Message&&);                     // move constructor
    Message& operator=(const Message&);     // copy-assignment operator
    Message& operator=(Message&&);          // move-assignment operator
    ~Message();                             // destructor
    // add/delete this message to/from a set of messages of the folder
    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents;       // text of this message
    std::set<Folder*> folders;   // all the folders that contain this message
    // a set of functions used by other methods
    // add this message to all folders of some other message
    void add_to_Folders(const Message&);
    // remove this message from all folders
    void remove_from_Folders();
    // move folders from paramenet to this message
    void move_Folders(Message*);
};
// swap two messages
void swap (Message&, Message&);

class Folder {
    friend class Message;
    friend void swap(Folder&, Folder&);
public:
    Folder() { }
    // copy control
    Folder(const Folder&);              // copy constructor
    Folder& operator= (const Folder&);  // copy-assignment operator
    ~Folder();                          // destructor
    // message manipulation
    addMsg(Message&); // add message to this folder
    remMsg(Message&); // remove message from this folder
private:
    std::set<Message*> messages; // messages this folder contains
    // a set of functions used by other methods
    // add all messages from other folder
    void add_to_Messages(const Folder&);
    //remove all messages
    void remove_from_Messages();
};
// swap two folders
void swap(Folder&, Folder&);

#endif

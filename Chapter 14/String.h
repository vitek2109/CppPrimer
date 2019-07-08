// This class is practically the same as StrVec, so i won't leave comments here
#ifndef STRING
#define STRING
#include <memory>
#include <algorithm>
#include <iostream>

class String {
    friend std::ostream &operator<< (std::ostream &, const String &);
    friend bool operator== (const String&, const String&);
public:
    String() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    String(const char*);
    String(const String&);
    String(String&&) noexcept;
    String& operator=(const String&);
    String& operator=(String&&) noexcept;
    ~String();
    char* begin() const { return elements; }
    char* end() const { return first_free; }
private:
    std::allocator<char> alloc;
    char* elements;
    char* first_free;
    char* cap;
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void free();
};

std::ostream &operator<< (std::ostream &, const String &);
bool operator== (const String&, const String&);
bool operator!= (const String&, const String&);

#endif

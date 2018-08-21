// This class is practically the same as StrVec, so i won't leave comments here
#ifndef STRING
#define STRING
#include <memory>
#include <algorithm>
#include <iostream>

class String {
public:
    String() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    String(const char*);
    String(const String&);
    String& operator=(const String&);
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

#endif
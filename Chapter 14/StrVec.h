#ifndef STRVEC
#define STRVEC
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <algorithm>

class StrVec {
    friend bool operator== (const String&, const String&);
public:
    // constructors
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const std::initializer_list<std::string>&);
    // copy control
    StrVec(const StrVec&);              // copy constructor
    StrVec(StrVec&&) noexcept;
    StrVec& operator=(const StrVec&);  // copy-assignment operator
    StrVec& operator=(StrVec&&) noexcept;
    ~StrVec();                          // destructor
    // few basic functions
    void push_back(const std::string&); // adds element to the end
    std::string at(size_t i) { return *(elements+i); }   // returns element at index i
    size_t size() const { return first_free - elements; } // returns number of initialized elements
    size_t capacity() const { return cap - elements; }    // returns number of allocated elements
    std::string* begin() const { return elements; } // returns pointer to the first element
    std::string* end() const { return first_free; } // returns pointer to the element after the last initialized
    void reserve(size_t n) { while(capacity() < n) reallocate(); }    // make sure there is at least n allocated elements
    void resize(size_t n, std::string s = "") { while(size() < n) push_back(s); }   // make sure there is at least n initialized elements, initialize new ones with s if needed
private:
    // memory control
    std::allocator<std::string> alloc;
    // pointers to
    std::string* elements;      // the very first element
    std::string* first_free;    // first non-initialized element
    std::string* cap;           // first non-existing element
    // utility methods
    // copy elements and return a pair of pointers to the new area
    std::pair<std::string*, std::string*>
        alloc_n_copy (const std::string*, const std::string*);
    // delete everything
    void free();
    // make sure there is enough space
    void chk_n_alloc();
    // make more space by moving everything
    void reallocate();
};

bool operator== (const String&, const String&);
bool operator!= (const String&, const String&);

#endif

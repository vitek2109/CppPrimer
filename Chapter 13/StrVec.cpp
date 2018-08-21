#include "StrVec.h"
#ifdef DEBUG
int main () { }
#endif

StrVec::StrVec(const std::initializer_list<std::string> &il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    elements = data.first;
    first_free = cap = data.second;
}
// copy control
StrVec::StrVec(const StrVec &sv)
{
    auto data = alloc_n_copy(sv.begin(), sv.end()); // returns a pair of pointers defining the area of values
    elements = data.first;                          // reassign all the pointers to the new area of values
    first_free = cap = data.second;
}
StrVec& StrVec::operator= (const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());   // returns a pair of pointers defining the area of values
    free();                                             // delete everything
    elements = data.first;                              // reassign all the pointers to the new area of values
    first_free = cap = data.second;
    return *this;
}
StrVec::~StrVec()
{
    free(); // delete everything
}
// push_back
void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();                      // make sure there's enough space
    alloc.construct(first_free++, s);   // add the element
}

// utility methods
std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);                      // allocate more memory
    return { data, std::uninitialized_copy(b, e, data) };   // copy everything there
}
void StrVec::free()
{
    if (elements) {                                             // if there are any elements
        for (auto p = first_free; p != elements; /* empty */)    // for every of them
            alloc.destroy(--p);                                 // destroy them
        alloc.deallocate(elements, cap-elements);               // deallocate all allocated space
    }
}
void StrVec::chk_n_alloc()
{
    if (cap == first_free)  // if these is no more space
        reallocate();       // make more space
}
void StrVec::reallocate()
{
    // make room for twice as many elements
    auto newcapacity = size() ? size() * 2 : 1;
    // allocate new space
    auto newdata = alloc.allocate(newcapacity);
    // move everything
    auto dest = newdata;                // beginning of new value range
    auto elem = elements;               // corresponding element from old value range
    for (size_t i = 0; i < size(); ++i) // move all elements
        alloc.construct(dest++, std::move(*elem++));
    // free old space
    free();
    // update the pointers
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}
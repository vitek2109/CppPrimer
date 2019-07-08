#include "String.h"
#ifdef DEBUG
int main() { }
#endif

String::String(const char *c)
{
    auto data = alloc_n_copy(c, c + (sizeof(c)/sizeof(*c)));
    elements = data.first;
    cap = first_free = data.second;
}
String::String(const String &s)
{
    std::cout << "Copy Constructor" << std::endl;
    auto data = alloc_n_copy(s.begin(), s.end());
    elements = data.first;
    cap = first_free = data.second;
}
String::String(String &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    std::cout << "Move Constuctor" << std::endl;
    s.elements = s.first_free = s.cap = nullptr;
}
String& String::operator=(const String &rhs)
{
    std::cout << "Copy-Assignment Operator" << std::endl;
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    cap = first_free = data.second;
}
String& String::operator=(String &&rhs) noexcept
{
    std::cout << "Move-Assignment Operator" << std::endl;
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}
String::~String()
{
    free();
}
std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
    auto data = alloc.allocate(e - b);
    return { data, std::uninitialized_copy(b, e, data) };
}
void String::free()
{
    if (elements) {
        for (auto p = first_free; p != elements; /* */)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap-elements);
    }
}

std::ostream &operator<< (std::ostream &os, const String &s) {
    for (auto b = s.begin(); b != s.end(); ++b)
        os << *b;
    return os;
}

bool operator== (const String& lhs, const String& rhs) {
    for (auto bl = lhs.begin, auto br = rhs.begin();
            bl != lhs.end() || br != rhs.end(); ++bl, ++br)
        if (*bl != *br)
            return false;
    return true;
}

bool operator!= (const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}

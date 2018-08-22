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
String& String::operator=(const String &rhs)
{
    std::cout << "Copy-Assignment Operator" << std::endl;
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    cap = first_free = data.second;
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

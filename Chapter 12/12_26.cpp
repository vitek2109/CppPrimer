#include <iostream>
#include <string>
#include <memory>

int main() 
{
    size_t size = 1024;
    std::allocator<std::string> alloc;
    auto p = alloc.allocate(size);
    std::string s;
    auto q = p;
    while (std::cin >> s && q != p + size)
        alloc.construct(q++, s);
    while (q != p) {
        std::cout << *(--q) << std::endl;
        alloc.destroy(q);
    }
    alloc.deallocate(p, size);
}

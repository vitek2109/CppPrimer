#include <iostream>
#include <list>
#include <string>

int main() {
    std::list<std::string> l{"Hello", "World", "Hello", "World", "!"};
    l.sort();
    l.unique();
    for (auto e : l)
        std::cout << e << ' ';
    std::cout << std::endl;
}
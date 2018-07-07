#include <forward_list>
#include <string>
#include <iostream>

void task (std::forward_list<std::string> &fl, std::string f, std::string i) {
    auto b = fl.begin();
    while (b != fl.end()) {
        if (*b == f)
            fl.insert_after(b++, i);
        ++b;
    }
}

int main() {
    std::forward_list<std::string> l = { "This", "A", "List", "Of", "Strings" };
    task (l, "This", "Is");
    for (auto i = l.begin(); i != l.end(); ++i)
        std::cout << *i << ' ';
    std::cout << std::endl;
}

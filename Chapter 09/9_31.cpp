#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = fli.before_begin();
    auto curr = fli.begin();
    while (curr != fli.end()) {
        if (*curr % 2) {
            fli.insert_after(curr, *curr);
            ++(++curr);
            ++(++prev);
        } else {
            curr = fli.erase_after(prev);
        }
    }
    for (auto i = fli.cbegin(); i != fli.end(); ++i)
        std::cout << *i << ' ';
    std::cout << std::endl;
}
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto b = v.cend() - 1; b != v.cbegin() - 1; --b)
        std::cout << *b << ' ';
    std::cout << std::endl;
}
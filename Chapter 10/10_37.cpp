#include <iostream>
#include <vector>
#include <list>

int main() {
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> l(v.rbegin()+3, v.rend() - 2);
    for (auto e : l)
        std::cout << e << ' ';
    std::cout << std::endl;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fill_n(v.begin(), v.size(), 0);
    for (auto b = v.cbegin(); b != v.cend(); ++b)
        std::cout << *b << ' ';
    std::cout << std::endl;
}
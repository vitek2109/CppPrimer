#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 42, 42, 10, 42, 5, 42, 6, 4, 8, 42};
    std::list<int> l;
    std::sort(v.begin(), v.end());
    std::unique_copy(v.begin(), v.end(), std::back_inserter(l));
    for (auto b = l.begin(); b != l.end(); ++b) 
        std::cout << *b << ' ';
    std::cout << std::endl;
}
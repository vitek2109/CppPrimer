#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> v{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    for (auto b = v.begin(); b != v.end(); ++b)
        std::cout << *b << ' ';
    std::cout << std::endl;

    sort(v.begin(), v.end());

    for (auto b = v.begin(); b != v.end(); ++b)
        std::cout << *b << ' ';
    std::cout << std::endl;

    auto end_unique = std::unique(v.begin(), v.end());

    for (auto b = v.begin(); b != v.end(); ++b)
        std::cout << *b << ' ';
    std::cout << std::endl;

    v.erase(end_unique, v.end());

    for (auto b = v.begin(); b != v.end(); ++b)
        std::cout << *b << ' ';
    std::cout << std::endl;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isShorter (const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

int main() {
    std::vector<std::string> v{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    std::sort(v.begin(), v.end());
    std::stable_sort(v.begin(), v.end(), isShorter);
    for (const auto &s : v)
        std::cout << s << ' ';
    std::cout << std::endl;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool longerThanFour (const std::string &s) {
    return s.size() > 4;
}

int main() {
    std::vector<std::string> v{"1", "12", "123", "1234", "12345", "123456", "1234567", "12345678", "123456789", "1234567890"};
    auto erase_begin = std::stable_partition(v.begin(), v.end(), longerThanFour);
    v.erase(erase_begin, v.end());
    for (const auto &s : v)
        std::cout << s << ' ';
    std::cout << std::endl;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std::placeholders;

bool longerThan(const std::string &s, std::string::size_type sz) {
    return s.size() > sz;
}

int main() {
    std::vector<std::string> v{"1", "12", "123", "1234", "12345", "123456", "1234567", "12345678", "123456789", "1234567890"};
    int n = 6;
    std::cout << "There are " << std::count_if(v.begin(), v.end(), std::bind(longerThan, _1, n)) << " words longer than " << n << '.' << std::endl;
}
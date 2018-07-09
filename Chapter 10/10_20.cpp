#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> v{"1", "12", "123", "1234", "12345", "123456", "1234567", "12345678", "123456789", "1234567890"};
    std::cout << "There are " << std::count_if(v.begin(), v.end(), [] (const std::string &s) { return s.size() > 6; }) << " words longer than 6." << std::endl;
}
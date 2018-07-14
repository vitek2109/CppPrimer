#include <iostream>
#include <string>

int main() {
    std::string s("ab2c3d7R4E6"), numbers("0123456789"), letters("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
    std::string::size_type pos = 0;
    std::cout << "Numbers: ";
    while ((pos = s.find_first_of(numbers, pos)) != std::string::npos) {
        std::cout << s[pos] << ' ';
        ++pos;
    }
    std::cout << std::endl << "Letters: ";
    pos = 0;
    while ((pos = s.find_first_of(letters, pos)) != std::string::npos) {
        std::cout << s[pos] << ' ';
        ++pos;
    }
    std::cout << std::endl;
}
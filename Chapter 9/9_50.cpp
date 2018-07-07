#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> v{"42.42", "24.12", "-24.54", "3.14", "-42"};
    double sum = 0;
    for (auto b = v.begin(); b != v.end(); ++b)
        sum += std::stod(*b);
    std::cout << sum << std::endl;
}

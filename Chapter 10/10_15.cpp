#include <iostream>

int main() {
    int a = 1;
    auto sum = [a] (const int &b) { return a + b; };
    std::cout << sum(2) << std::endl;
}
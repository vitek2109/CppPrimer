#include <iostream>

int main()
{
    // a
    std::cout << -30 * 3 + 21 / 5 << std::endl; // -86
    // b
    std::cout << -30 + 3 * 21 / 5 << std::endl; // -18
    // c
    std::cout << 30 / 3 * 21 % 5  << std::endl; // 0
    // d
    std::cout << -30 / 3 * 21 % 4 << std::endl; // -2
}

#include <iostream>

int main()
{
    int n, m;
    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> n >> m;
    std::cout << "Numbers between " << n << " and " << m << " inclusive are:" << std::endl;
    while (n <= m) {
        std::cout << n << " ";
        ++n;
    }
    std::cout << std::endl;
    return 0;
}

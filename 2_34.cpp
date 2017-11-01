#include <iostream>

int main()
{
    int i = 0, &r = i;
    const int ci = i, &cr = ci;
    auto a = r;   // int
    auto b = ci;  // int
    auto c = cr;  // int
    auto d = &i;  // int*
    auto e = &ci; // const int*
    auto &g = ci; // const int&
    std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << g << std::endl;
    a = 42;
    b = 42;
    c = 42;
    // d = 42;
    // e = 42;
    // g = 42;
    std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << g << std::endl;
}

#include <iostream>

int main()
{
    int i = 42;
    int *ip = nullptr;
    ip = &i;
    *ip = 24;
    std::cout << ip << " " << *ip << std::endl;
}

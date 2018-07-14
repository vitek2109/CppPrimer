#include <iostream>
int main()
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    // for (int i = 0; i <= array_size; ++i)
    for (int i = 0; i < array_size; ++i)
        ia[i] = 0;
}
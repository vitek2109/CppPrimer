#include <iostream>
int main()
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    for (int i = 0; i < array_size; ++i)
        ia[i] = 0;
    int ia2[array_size];
    for (int i = 0; i < array_size; ++i)
        ia2[i] = ia[i];
}
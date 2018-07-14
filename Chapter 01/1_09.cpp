#include <iostream>

int main()
{
    int sum = 0;
    int i = 50;
    while (i < 101)
    {
        sum += i;
        ++i;
    }
    std::cout << "The sum of 50 through 100 inclusive is: " << sum << std::endl;
}

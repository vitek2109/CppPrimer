#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 50; i < 101; ++i)
        sum += i;
    std::cout << "The sum of 50 through 100 inclusive is: " << sum << std::endl;
}

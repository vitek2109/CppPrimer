#include <iostream>

int main()
{
    int i, sum = 0;
    std::cout << "Enter the numbers:\n";
    while(std::cin >> i)
        sum += i;
    std::cout << "The sum of given numbers is: " << sum << std::endl;
}

#include <iostream>

using std::cout; using std::endl;

int main()
{
    int i = 50, sum = 0;
    while (i <= 100)
        sum += i++;
    cout << "The sum of 50 to 100 inclusive is: " << sum << endl;
}
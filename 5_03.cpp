#include <iostream>
using std::cout; using std::endl;

int main()
{
    int sum = 0, val = 1;
    while(val <= 10)
        sum += val, ++val;
    cout << "The sum of 1 to 10 inclusive is " << sum << endl;
}

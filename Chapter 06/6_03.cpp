#include <iostream>
using std::cout; using std::endl;

// n! = n * (n-1) * (n-2) * ... * 3 * 2 * 1
int fact (int n)
{
    int r = 1;
    while (n > 1)
        r *= n--;
    return r;
}

int main()
{
    cout << fact(5) << endl;
}
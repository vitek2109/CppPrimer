#include <iostream>
using std::cout; using std::endl;

void reset (int &n)
{
    n = 0;
}

int main()
{
    int n = 1;
    reset(n);
    cout << n << endl;
}
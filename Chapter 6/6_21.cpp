#include <iostream>
using std::cout; using std::endl;

int max (const int &n, const int *p)
{
    return n >= *p ? n : *p;
}

int main()
{
    int a = 1, b = 2;
    cout << max(a, &b) << endl;
}
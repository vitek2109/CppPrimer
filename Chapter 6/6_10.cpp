#include <iostream>
using std::cout; using std::endl;

void swap (int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main()
{
    int n = 2, m = 4;
    int *p = &n, *q = &m;
    swap (p, q);
    cout << n << m << endl;
}
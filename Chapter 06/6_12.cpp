#include <iostream>
using std::cout; using std::endl;

void swap (int &n, int &m)
{
    int temp = n;
    n = m;
    m = temp;
}

int main()
{
    int n = 2, m = 4;
    swap (n, m);
    cout << n << m << endl;;
}
#include <iostream>
using std::cout; using std::endl; using std::cin;

// abs(n) = | n , n >= 0
//          | -n, n <  0
int abs (int n)
{
    return n < 0 ? -n : n;
}

int main()
{
    int n;
    cin >> n;
    cout << abs(n) << endl;
}
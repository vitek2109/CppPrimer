#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
    int n, m;
    cout << "Enter two numbers:\n";
    cin >> n >> m;
    if (n > m)
    {
        int temp = n;
        n = m;
        m = temp;
    }
    while(n <= m)
        cout << n++ << endl;
}
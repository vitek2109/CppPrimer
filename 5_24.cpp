#include <iostream>
#include <stdexcept>
using std::cout; using std::endl; using std::cin; using std::runtime_error;

int main()
{
    int n, m;
    cin >> n >> m;
    if (m == 0)
        throw runtime_error("Division by zero!");
    cout << n/m << endl;
}
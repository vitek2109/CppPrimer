#include <iostream>
#include <initializer_list>
using std::cout; using std::endl; using std::initializer_list;

int sum (initializer_list<int> il)
{
    int s = 0;
    for (int i : il)
        s += i;
    return s;
}

int main()
{
    cout << sum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << endl;
}
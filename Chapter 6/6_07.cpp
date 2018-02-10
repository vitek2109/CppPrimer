#include <iostream>
using std::cout; using std::endl;

int count_calls ()
{
    static int n = 0;
    return n++;
}

int main()
{
    for (int i = 0; i < 10; ++i)
        cout << count_calls() << endl;
}
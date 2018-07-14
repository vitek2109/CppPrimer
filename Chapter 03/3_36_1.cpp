#include <iostream>
using std::cout; using std::endl;
int main()
{
    int a[10] =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bool equal = true;
    for (int i = 0; i < 10; i++)
        if (a[i] != a2[i])
        {
            equal = false;
            break;
        }
    cout << equal << endl;
}
#include <iostream>
using std::cout; using std::endl;
using int_array = int[4];
int main()
{
    int_array ia[3] = {
        {0, 1, 2 , 3 },
        {4, 5, 6 , 7 },
        {8, 9, 10, 11}
    };
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
            cout << ia[i][j] << ' ';
        cout << endl;
    }
}
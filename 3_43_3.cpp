#include <iostream>
#include <iterator>
using std::cout; using std::endl; using std::begin; using std::end;
int main()
{
    int ia[3][4] = {
        {0, 1, 2 , 3 },
        {4, 5, 6 , 7 },
        {8, 9, 10, 11}
    };
    for (int (*p1)[4] = begin(ia); p1 != end(ia); ++p1)
    {
        for (int *p2 = begin(*p1); p2 != end(*p1); ++p2)
            cout << *p2 << ' ';
        cout << endl;
    }
}
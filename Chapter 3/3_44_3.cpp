#include <iostream>
#include <iterator>
using std::cout; using std::endl; using std::begin; using std::end;
using int_array = int[4];
int main()
{
    int_array ia[3] = {
        {0, 1, 2 , 3 },
        {4, 5, 6 , 7 },
        {8, 9, 10, 11}
    };
    for (int_array *p1 = begin(ia); p1 != end(ia); ++p1)
    {
        for (int *p2 = begin(*p1); p2 != end(*p1); ++p2)
            cout << *p2 << ' ';
        cout << endl;
    }
}
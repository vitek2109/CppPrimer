#include <vector>
using std::vector;
int main()
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v;
    for ( auto i : a )
        v.push_back(i);
}
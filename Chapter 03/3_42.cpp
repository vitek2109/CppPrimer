#include <vector>
using std::vector;
int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a[v.size()];
    for(int i = 0; i < v.size(); ++i)
        a[i] = v[i];
}
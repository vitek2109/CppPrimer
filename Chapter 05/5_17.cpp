#include <iostream>
#include <vector>
using std::cout; using std::endl; using std::vector;

int main()
{
    vector<int> v1 = {0, 1, 1, 2}, 
                v2 = {0, 1, 1, 2, 3, 5, 8};
    if (v1.size() > v2.size())
    {
        vector<int> temp = v1;
        v1 = v2;
        v2 = temp;
    }
    for (int i = 0; i < v1.size(); ++i)
        if (v1[i] != v2[i])
        {
            cout << "false" << endl;
            return 0;
        }
    cout << "true" << endl;
}
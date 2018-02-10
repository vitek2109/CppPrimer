#include <iostream>
#include <vector>
using std::cout; using std::endl; using std::vector;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto iter = vec.begin(); iter != vec.end(); ++iter)
        cout << ((*iter % 2 == 0) ? *iter : *iter * 2) << ' ';
    cout << endl;
}

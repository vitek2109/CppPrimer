#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::vector;

int main()
{
    vector<int> vec;
    int n;
    while (cin >> n)
        vec.push_back(n);
    for (auto beg = vec.begin(); beg != vec.end() - 1; beg++)
    {
        cout << *beg + *(beg+1) << " ";
    }
    cout << endl;
}
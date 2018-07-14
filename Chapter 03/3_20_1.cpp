#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::vector;

int main()
{
    vector<int> vec;
    int i;
    while (cin >> i)
        vec.push_back(i);
    for (i = 0; i < vec.size() - 1; i++)
        cout << vec[i] + vec[i+1] << " ";
    cout << endl;
}
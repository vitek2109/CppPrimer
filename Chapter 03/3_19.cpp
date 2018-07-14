#include <vector>

using std::vector;

int main()
{
    // (1) : Most understandable and short
    vector<int> v1(10, 42);
    // (2)
    vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    // (3)
    vector<int> v3;
    for (int i = 0; i < 10; i++)
        v3.push_back(42);
}
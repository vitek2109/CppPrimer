#include <iostream>
#include <vector>

using std::vector;

int main()
{
    constexpr int vector_size = 10;
    vector<int> vec;
    for (int i = 0; i < vector_size; ++i)
        vec.push_back(i);
    vector<int> vec2 = vec;
}
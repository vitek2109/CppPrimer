#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << std::accumulate(v.begin(), v.end(), 0) << std::endl;
}
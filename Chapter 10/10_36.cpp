#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto f = std::find(v.crbegin(), v.crend(),  0);
}
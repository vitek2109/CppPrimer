#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v;
    int n;
    std::cout << "Enter the sequence:" << std::endl;
    while (std::cin >> n)
        v.push_back(n);
    std::cout << "The 42 appeared " << std::count(v.begin(), v.end(), 42) << " times." << std::endl;
}
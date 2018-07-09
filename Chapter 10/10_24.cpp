#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std::placeholders;

bool check_size (const std::string &s, std::string::size_type sz) {
    return sz > s.size();
}

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 42};
    std::string s("Hello World!");
    std::cout << *(std::find_if(v.begin(), v.end(), std::bind(check_size, s, _1))) << std::endl;
}
#include <iostream>
#include <map>

int main() {
    std::map<int, int> m;
    int i = 1;
    m[i] = 2;
    std::cout << m[i] << std::endl;
}
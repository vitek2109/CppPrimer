#include <iostream>
#include <map>

int main() {
    std::map<int, int> m = {{1, 1}};
    auto m_it = m.begin();
    m_it->second = 2;
    std::cout << m[1] << std::endl;
}
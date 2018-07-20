#include <iostream>
#include <vector>
#include <string>
#include <utility>

int main() {
    std::vector<std::pair<std::string, int>> v;
    while (true) {
        std::string s;
        if (!(std::cin >> s))
            break;
        int n;
        if (!(std::cin >> n))
            break;
        v.push_back(make_pair(s, n));
    }
    for (auto e : v) {
        std::cout << e.first << " : " << e.second << std::endl;
    }
}
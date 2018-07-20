#include <map>
#include <string>
#include <vector>
#include <utility>

int main() {
    std::map<std::string, std::vector<int>> m;
    std::pair<std::map<std::string, std::vector<int>>::iterator, bool> ret = m.insert(std::pair<std::string, std::vector<int>>(std::string("Hello"), std::vector<int>{1, 2, 3, 4}));
}
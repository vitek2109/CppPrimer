#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

void new_children (std::multimap<std::string, std::vector<std::pair<std::string, std::string>>> &families, std::string family, const std::vector<std::pair<std::string, std::string>> children) {
    families.insert(make_pair(family, children));
}

int main() {
    std::multimap<std::string, std::vector<std::pair<std::string, std::string>>> families;
    new_children (families, "Jonhson", {{"Jonh", "01/01"}, {"Jack", "01/01"}});
    new_children (families, "Smith", {{"Sam", "01/01"}, {"Spencer", "01/01"}});
    for (auto e : families) {
        std::cout << e.first << ": ";
        for (auto p : e.second) {
            std::cout << p.first << " " << p.second << ", ";
        }
        std::cout << std::endl;
    }
}
